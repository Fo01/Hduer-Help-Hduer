<?php

namespace App\Library\Imap\Message;

interface MessageInterface
{
        public function __construct($connection);
        public function setSubject(string $subject);
        public function getSubject() : string;
        public function setFrom(string $from);
        public function getFrom() : string;
        public function setTo(string $to);
        public function getTo() : string;
        public function setDate(string $date);
        public function getDate() : \DateTime;
        public function setMessageId(string $id);
        public function getMessageId() : string;
        public function setReferences(string $refs);
        public function getReferences() : string;
        public function setInReplyTo(string $to);
        public function getInReplyTo() : string;
        public function setSize(int $size);
        public function getSize() : int;
        public function setUID(string $uid);
        public function getUID() : string;
        public function setMessageNo(int $no);
        public function getMessageNo() : int;
}