<?php

namespace App\Library\Imap;

class GmailConnection extends AbstractConnection
{
    protected $hostname = 'imap.gmail.com';
    protected $port = 993;
    protected $path = '/imap/ssl';
    protected $mailbox = 'INBOX';
    
}