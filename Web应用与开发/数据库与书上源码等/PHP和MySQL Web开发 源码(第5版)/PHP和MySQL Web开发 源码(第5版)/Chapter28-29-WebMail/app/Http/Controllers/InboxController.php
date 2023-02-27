<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Pagination\LengthAwarePaginator;

class InboxController extends Controller
{
    protected function getImapClient()
    {
        $credentials = \Session::get('credentials');
        
        $client = \App::make('Imap\Connection\GMail')
                      ->setUsername($credentials['user'])
                      ->setPassword($credentials['password'])
                      ->connect();
        
        return $client;
    }
        
    public function getInbox(Request $request)
    {
        $client = $this->getImapClient();    
    
        $currentMailbox = $request->get('box', $client->getCurrentMailbox());
    
        $mailboxes = $client->getMailboxes();
        
        if($currentMailbox != $client->getCurrentMailbox()) {
            
            if(in_array($currentMailbox, $mailboxes)) {
                $client->setCurrentMailbox($currentMailbox);
            }
        }
    
        $page = $request->get('page', 1);
        $messages = $client->getPage($request->get('page', 1));
        
        $paginator = new LengthAwarePaginator(
                $messages, 
                $client->getCount(), 
                25, 
                $page, [
                    'path' => '/inbox'
        ]);
        
        return view('app.inbox', compact('messages', 'mailboxes', 'currentMailbox', 'paginator'));
    }
    
    public function getMessage(Request $request)
    {
        $client = $this->getImapClient();
        
        $currentMailbox = $request->get('box', $client->getCurrentMailbox());
        
        $mailboxes = $client->getMailboxes();
        
        if($currentMailbox != $client->getCurrentMailbox()) {
        
            if(in_array($currentMailbox, $mailboxes)) {
                $client->setCurrentMailbox($currentMailbox);
            }
        }
        
        $messageId = $request->route('id');

        $message = $client->getMessage($messageId)->fetch();

        return view('app.read', compact('currentMailbox', 'mailboxes', 'message'));
    }
    
    public function getAttachment(Request $request)
    {
        $client = $this->getImapClient();
        
        $messageId = $request->route('id');
        $attachmentPart = $request->route('partId');
        
        $message = $client->getMessage($messageId)->fetch();
        
        $attachment = $message->getAttachmentByPartId($attachmentPart)->fetch();
        
        return response()->make($attachment->getData(), 200, [
            'Content-Type' => $attachment->getMimeType(),
            'Content-Disposition' => "attachment; filename=\"{$attachment->getFilename()}\""
        ]);
        
    }
    
    public function getCompose(Request $request) 
    {
        $client = $this->getImapClient();
        
        $mailboxes = $client->getMailboxes();
        
        $messageId = $request->route('id');
        
        $quotedMessage = '';
        $message = null;
        
        if(!is_null($messageId)) {
            $message = $client->getMessage($messageId)->fetch();
            $quotedMessage = $message->getPlainBody();
            
            $messageLines = explode("\n", $quotedMessage);
            
            foreach($messageLines as &$line) {
                $line = ' > ' . $line;
            }
            
            $quotedMessage = implode("\n", $messageLines);
        }
        
        return view('app.compose', compact('quotedMessage', 'message', 'mailboxes'));
    }
    
    public function getDelete(Request $request) 
    {
        $client = $this->getImapClient();
        
        $messageId = $request->route('id');
        
        $client->deleteMessage($messageId);
        
        return redirect('inbox')->with('success', "Message Deleted");
    }
    
    public function postSend(Request $request) 
    {
        $this->validate($request, [
            'from' => 'required|email',
            'to' => 'required|email',
            'subject' => 'required|max:255',
            'message' => 'required'
        ]);
        
        $from = $request->input('from');
        $to = $request->input('to');
        $subject = $request->input('subject');
        $message = $request->input('message');
        
        \Mail::raw($message, function($message) use ($to, $from, $subject) {
            $message->from($from);
            $message->to($to);
            $message->subject($subject);
        });
        
        return redirect('inbox')->with('success', 'Message Sent!');
    }
}