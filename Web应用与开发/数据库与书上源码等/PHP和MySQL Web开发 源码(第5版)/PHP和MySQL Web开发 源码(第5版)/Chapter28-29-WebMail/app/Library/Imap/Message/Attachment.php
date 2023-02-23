<?php

namespace App\Library\Imap\Message;

class Attachment
{
    protected $_mimeType;
    protected $_size;
    protected $_filename;
    protected $_data;
    protected $_message;
    protected $_partId;
    protected $_encoding;
    
    public function __construct(Message $msg) 
    {
        $this->_message = $msg;
    }
    
    public function getEncoding() : string
    {
        return $this->_encoding;
    }
    
    public function setEncoding($enc) : self
    {
        $this->_encoding = $enc;
        return $this;
    }
    
    public function getPartId() : string
    {
        return $this->_partId;
    }
    
    public function setPartId($partId) : self
    {
        $this->_partId = $partId;
        return $this;
    }
    
    public function getMimeType() : string
    {
        return $this->_mimeType;
    }
    
    public function setMimeType($type) : self
    {
        $this->_mimeType = $type;
        return $this;
    }
    
    public function getSize() : int
    {
        return $this->_size;
    }
    
    public function setSize($size) : self
    {
        $this->_size = $size;
        return $this;
    }
    
    public function getFilename() : string
    {
        return $this->_filename;
    }
    
    public function setFilename($filename) : self
    {
        $this->_filename = $filename;
        return $this;
    }
    
    public function getData() : string
    {
        return $this->_data;
    }
    
    public function setData($data) : self
    {
        $this->_data = $data;
        return $this;
    }
    
    public function fetch() : self
    {
        $body = imap_fetchbody(
                    $this->_message->getConnection(),
                    $this->_message->getMessageNo(),
                    $this->_partId,
                    FT_PEEK);
        
        switch($this->getEncoding()) {
            case 'quoted-printable':
            case ENCQUOTEDPRINTABLE:
                $body = quoted_printable_decode($body);
                break;
            case 'base64':
            case ENCBASE64:
                $body = base64_decode($body);
                break;
        }
        
        $this->setData($body);
        
        return $this;
    }
}