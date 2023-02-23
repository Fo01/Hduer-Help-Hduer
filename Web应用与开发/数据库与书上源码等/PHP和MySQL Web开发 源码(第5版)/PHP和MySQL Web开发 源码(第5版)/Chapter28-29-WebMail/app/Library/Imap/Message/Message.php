<?php

namespace App\Library\Imap\Message;

use Illuminate\Contracts\Support\Htmlable;

class Message implements MessageInterface, Htmlable
{
    protected $_subject = '';
    protected $_from = '';
    protected $_to = '';
    protected $_date = null;
    protected $_messageId = '';
    protected $_references = '';
    protected $_inReplyTo = '';
    protected $_size = 0;
    protected $_UID = '';
    protected $_msgNo = 0;
    
    protected $_plainBody = '';
    protected $_htmlBody = '';
    
    protected $_connection = null;
    
    protected $_attachments = [];
    
public function __construct($connection)
{
    $this->_date = new \DateTime('now');
    
    if(!is_resource($connection)) {
        throw new \InvalidArgumentException("Constructor must be passed IMAP resource");
    }
    
    $this->_connection = $connection;
}
    
    public function toHtml() : string
    {
        if(!empty($this->_htmlBody)) {
            return $this->_htmlBody;
        }
        
        return nl2br($this->_plainBody);
    }
    
    public function getAttachments() : array 
    {
        return $this->_attachments;
    }
    
    public function getConnection() 
    {
        return $this->_connection;
    }
    
    public function getAttachmentByPartId(string $partId) 
    {
        if(!isset($this->_attachments[$partId])) {
            return null;
        }
        
        return $this->_attachments[$partId];
    }
    
    public function getHtmlBody() : string
    {
        return $this->_htmlBody;
    }
    
    public function getPlainBody() : string
    {
        return $this->_plainBody;
    }
    
    public function hasHtmlBody() : boolean
    {
        return !empty($this->_htmlBody);
    }
    
    protected function processStruct($structure, $partId = null)
    {
        $params = [];
        $self = $this;
        
        $recurse = function($struct) use ($partId, $self) {
            if(isset($struct->parts) && is_array($struct->parts)) {
                
                foreach($struct->parts as $idx => $part) {
                    $curPartId = $idx +1;

                    if(!is_null($partId)) {
                        $curPartId = $partId . '.' . $curPartId;
                    }
                    
                    $self->processStruct($part, $curPartId);
                }
            }
            
            return $self;
        };
        
        if(isset($structure->parameters)) {
            foreach($structure->parameters as $param) {
               $params[strtolower($param->attribute)] = $param->value;     
            }
        }
        
        if(isset($structure->dparameters)) {
            foreach($structure->dparameters as $param) {
                $params[strtolower($param->attribute)] = $param->value;
            }
        }
        
        if(isset($params['name']) || isset($params['filename']) ||
           (isset($structure->subtype) && strtolower($structure->subtype) == 'rfc822')) {
               // Process attachement
               
               $filename = isset($params['name']) ? $params['name'] : $params['filename'];
               
               $attachment = new Attachment($this);
               
               $attachment->setFilename($filename)
                          ->setEncoding($structure->encoding)
                          ->setPartId($partId)
                          ->setSize($structure->bytes);
                          
               switch($structure->type) {
                   case TYPETEXT:
                       $mimeType = 'text';
                       break;
                   case TYPEMESSAGE:
                       $mimeType = 'message';
                       break;
                   case TYPEAPPLICATION:
                       $mimeType = 'application';
                       break;
                   case TYPEAUDIO:
                       $mimeType = 'audio';
                       break;
                   case TYPEIMAGE:
                       $mimeType = 'image';
                       break;
                   case TYPEVIDEO:
                       $mimeType = 'video';
                       break;
                   default:
                   case TYPEOTHER:
                       $mimeType = 'other';
                       break;
               }
               
               $mimeType .= '/' . strtolower($structure->subtype);
               
               $attachment->setMimeType($mimeType);
               
               $this->_attachments[$partId] = $attachment;
               
               return $recurse($structure);
        }
        
        if(!is_null($partId)) {
            $body = imap_fetchbody($this->_connection, $this->getMessageNo(), $partId, FT_PEEK);
        } else {
            $body = imap_body($this->_connection, $this->getUID(), FT_UID | FT_PEEK);
        }
        
        $encoding = strtolower($structure->encoding);
        
        switch($structure->encoding) {
            case 'quoted-printable':
            case ENCQUOTEDPRINTABLE:
                $body = quoted_printable_decode($body);
                break;
            case 'base64':
            case ENCBASE64:
                $body = base64_decode($body);
                break;
        }
        
        $subtype = strtolower($structure->subtype);
        
        switch(true) {
            case $subtype == 'plain':
                if(!empty($this->_plainBody)) {
                    $this->_plainBody .= PHP_EOL . PHP_EOL . trim($body);
                } else {
                    $this->_plainBody = trim($body);
                }
                break;
            case $subtype == 'html':
                if(!empty($this->_htmlBody)) {
                    $this->_htmlBody .= '<br><br>' . $body;
                } else {
                    $this->_htmlBody = $body;
                }
                break;
        }
        
        return $recurse($structure);
    }
    
    public function fetch(int $options = 0) : self
    {
        $structure = imap_fetchstructure($this->_connection,  $this->getMessageNo(), $options);
        
        if(!$structure) {
            return $this;
        }
        
        switch($structure->type) {
            case TYPEMULTIPART:
            case TYPETEXT:
                $this->processStruct($structure);
                break;
            case TYPEMESSAGE:
                break;
            case TYPEAPPLICATION:
            case TYPEAUDIO:
            case TYPEIMAGE:
            case TYPEVIDEO:
            case TYPEMODEL:
            case TYPEOTHER:
                break;
        }
        
        return $this;
    }
    
    public function setSubject(string $subject) : self
    {
        $this->_subject = $subject;
        return $this;
    }
    
    public function getSubject() : string
    {
        return $this->_subject;
    }
    
    public function setFrom(string $from) : self
    {
        $this->_from = $from;
        return $this;
    }
    
    public function getFrom() : string
    {
        return $this->_from;
    }
    
    public function getToEmail() : string
    {
        $to = $this->getTo();
        
        $addressList = imap_rfc822_parse_adrlist($to, "");
        
        if(empty($addressList)) {
            return '';
        }
        
        $address = array_pop($addressList);
        
        return "{$address->mailbox}@{$address->host}";
    }
    
    public function getFromEmail() : string
    {
        $from = $this->getFrom();
        
        $addressList = imap_rfc822_parse_adrlist($from, "");
        
        if(empty($addressList)) {
            return '';
        }
        
        $address = array_pop($addressList);
        
        return "{$address->mailbox}@{$address->host}";
    }
    
    public function setTo(string $to) : self
    {
        $this->_to = $to;
        return $this;
    }
    
    public function getTo() : string
    {
        return $this->_to;
    }
    
    public function setDate(string $date) : self
    {
        $this->_date = new \DateTime($date);
        return $this;
    }
    
    public function getDate() : \DateTime
    {
        return $this->_date; 
    }
    
    public function setMessageId(string $id) : self
    {
        $this->_messageId = $id;
        return $this;
    }
    
    public function getMessageId() : string
    {
        return $this->_messageId;
    }
    
    public function setReferences(string $refs) : self
    {
        $this->_references = $refs;
        return $this;
    }
    
    public function getReferences() : string
    {
        return $this->_references;
    }
    
    public function setInReplyTo(string $to) : self
    {
        $this->_inReplyTo = $to;
        return $this;
    }
    
    public function getInReplyTo() : string
    {
        return $this->_inReplyTo;
    }
    
    public function setSize(int $size) : self
    {
        $this->_size = $size;
        return $this;
    }
    
    public function getSize() : int
    {
        return $this->_size;
    }
    
    public function setUID(string $uid) : self
    {
        $this->_UID = $uid;
        return $this;
    }
    
    public function getUID() : string
    {
        return $this->_UID;
    }
    
    public function setMessageNo(int $no) : self
    {
        $this->_msgNo = $no;
        return $this;
    }
    
    public function getMessageNo() : int
    {
        return $this->_msgNo;
    }
}