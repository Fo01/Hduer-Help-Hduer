<?php

namespace App\Library\Imap;

abstract class AbstractConnection
{
    protected $_username;
    protected $_password;
    
    protected $hostname = '';
    protected $port = 993;
    protected $path = '/imap/ssl';
    protected $mailbox = 'INBOX';
    
    public function getUsername() : string
    {
        return $this->_username;
    }
    
    public function getPassword() : string
    {
        return $this->_password;
    }
    
    public function setUsername(string $username) : self
    {
        $this->_username = $username;
        return $this;
    }
    
    public function setPassword(string $password) : self
    {
        $this->_password = $password;
        return $this;
    }
    
    public function connect(int $options = 0, int $n_retries = 0, array $params = []) : \App\Library\Imap\Client
    {
        $connection = imap_open(
            $this->getServerRef(),
            $this->getUsername(),
            $this->getPassword(),
            $options,
            $n_retries,
            $params
        );
        
        if(!is_resource($connection)) {
            throw new ImapException("Failed to connect to server");
        }
        
        return new Client($connection, $this->getServerDetails());
    }
    
    protected function getServerDetails()
    {
        return [
            'hostname' => $this->hostname,
            'port' => $this->port,
            'path' => $this->path,
            'mailbox' => $this->mailbox
        ];
    }
    
    protected function getServerRef() 
    {
        if(is_null($this->hostname)) {
            throw new \Exception("No Hostname provided");
        }
        
        $serverRef = '{' . $this->hostname;
        
        if(!empty($this->port)) {
            $serverRef .= ':' . $this->port;
        }
        
        if(!empty($this->path)) {
            $serverRef .= $this->path;
        }
        
        $serverRef .= '}' . $this->mailbox;
        
        return $serverRef;
    }
}