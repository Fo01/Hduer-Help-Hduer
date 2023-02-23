<?php

namespace App\Library\Imap;

use App\Library\Imap\Message\MessageInterface;
use Illuminate\Support\Collection;
use App\Library\Imap\Message\Message;

class Client
{
    protected $_connection;
    protected $_prototype;
    protected $_spec;
    protected $_currentMailbox;
    
    public function __construct($connection, array $spec)
    {
        if(!is_resource($connection)) {
            throw new \InvalidArgumentException("Must provide an IMAP connection resource");
        }
        
        $this->_prototype = new Message($connection);
        
        $this->_connection = $connection;
        $this->_spec = $spec;
        $this->_currentMailbox = $spec['mailbox'];
    }
        
    public function getCurrentMailbox() : string
    {
        return $this->_currentMailbox;
    }
    
    public function setCurrentMailbox(string $box, int $options = 0, int $n_retries = 0) : self
    {
        $this->_currentMailbox = $box;
        
        if(!imap_reopen($this->_connection, $this->getServerRef() . $this->_currentMailbox, $options, $n_retries)) {
            throw new ImapException("Failed to open Mailbox: $box");
        }
        
        return $this;
    }
    
    public function setPrototype(MessageInterface $obj) : self
    {
        $this->_prototype = $obj;
        return $this;
    }
    
    public function getPrototype() : MessageInterface
    {
        return clone $this->_prototype;
    }
    
    public function deleteMessage($id, int $options = 0) : self
    {
        imap_delete($this->_connection, $id, $options);
        return $this;
    }
    
    public function getMessage($id, int $options = 0) : \App\Library\Imap\Message\MessageInterface
    {
        $overview = imap_fetch_overview($this->_connection, $id, $options);
        
        if(empty($overview)) {
            return $this->getPrototype();
        }

        $overview = array_pop($overview);
        
        $retval = $this->getPrototype();
        
        $retval->setSubject($overview->subject)
               ->setFrom($overview->from)
               ->setTo($overview->to)
               ->setDate($overview->date)
               ->setMessageId($overview->message_id)
               ->setSize($overview->size)
               ->setUID($overview->uid)
               ->setMessageNo($overview->msgno);
        
        return $retval;
    }
    
    protected function getServerRef()
    {
        $serverRef = '{' . $this->_spec['hostname'];
        
        if(!empty($this->_spec['port'])) {
            $serverRef .= ':' . $this->_spec['port'];
        }
        
        if(!empty($this->_spec['path'])) {
            $serverRef .= $this->_spec['path'];
        }
        
        $serverRef .= '}';
        
        return $serverRef;
    }
        
    public function getMailboxes($pattern = '*') 
    {
    
        $serverRef = $this->getServerRef();
        
        $result = imap_list($this->_connection, $serverRef, $pattern);
        
        if(!is_array($result)) {
            return [];
        }
        
        $retval = [];
        
        foreach($result as $mailbox) {
            $retval[] = str_replace($serverRef, '', $mailbox);    
        }
        
        return $retval;
    }
    
    public function getCount()
    {
        $boxInfo = imap_check($this->_connection);
        
        return $boxInfo->Nmsgs;
    }
    
    public function getPage(int $page = 1, int $perPage = 25, $options = 0) : \Illuminate\Support\Collection
    {
        $boxInfo = imap_check($this->_connection);
         
        $start = $boxInfo->Nmsgs - ($perPage * $page);
        $end = $start + ($perPage - (($page > 1) ? 1 : 0) );
        
        if($start < 1) {
            $start = 1;
        }
        
        $overview = imap_fetch_overview($this->_connection, "$start:$end", $options);
        $overview = array_reverse($overview);
        
        $collection = new Collection();
        
        foreach($overview as $key => $msg) {
            $msgObj = $this->getPrototype();
            
            $msgObj->setSubject($msg->subject)
                   ->setFrom($msg->from)
                   ->setTo($msg->to)
                   ->setDate($msg->date)
                   ->setMessageId($msg->message_id)
                   ->setSize($msg->size)
                   ->setUID($msg->uid)
                   ->setMessageNo($msg->msgno);
            
            if(isset($msg->references)) {
                $msgObj->setReferences($msg->references);
            }
            
            if(isset($msg->in_reply_to)) {
                $msgObj->setInReplyTo($msg->in_reply_to);
            }
            
            $collection->put($key, $msgObj);
        }
        
        return $collection;
    }
}