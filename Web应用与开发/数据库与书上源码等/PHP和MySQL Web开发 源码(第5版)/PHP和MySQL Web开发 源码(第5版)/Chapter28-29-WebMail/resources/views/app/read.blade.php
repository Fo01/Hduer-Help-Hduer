@extends('layouts.authed')

@section('stylesheets')
@parent
<link href="/css/app.css" rel="stylesheet"/>
@stop

@section('main')
<div class="row">
    <div class="col-md-3">
        <div class="text-center"><h2>Mailboxes</h2></div>
        <div class="panel panel-default">
            <div class="panel-body">
                <a href="/compose" class="btn btn-primary btn-block">Compose</a>
                <ul class="folders">
                    @foreach($mailboxes as $mailbox)
                    <li>
                        <a href="/inbox?box={{{ $mailbox }}}"><i class="glyphicon glyphicon-inbox"></i> {{{ $mailbox }}}</a>
                    </li>
                    @endforeach
                </ul>
            </div>
        </div>
    </div>
    
    <div class="col-md-9">
    <div class="text-center"><h2>Webmail Demo - {{{ $currentMailbox }}}</h2></div>
        <div class="panel panel-default">
            <div class="panel-body">
                <div class="header">
                    <span class="from">
                        {{{ $message->getFrom() }}}
                    </span>
                    <span class="subject">
                        {{{ $message->getSubject() }}}
                        <span class="date">
                            {{{ $message->getDate()->format('F jS, Y') }}}
                        </span>
                    </span>
                </div>
                <hr/>
                <div class="btn-group pull-right">
                    <a href="/compose/{{ $message->getMessageNo() }}" class="btn btn-default"><i class="glyphicon glyphicon-envelope"></i> Reply</a>
                    <a href="/inbox/delete/{{ $message->getMessageNo() }}" class="btn btn-default"><i class="glyphicon glyphicon-trash"></i> Delete</a>
                </div>
                <div class="messageBody">
                {{ $message }}
                @if(!empty($message->getAttachments()))
                    <hr/>
                    @foreach($message->getAttachments() as $part => $attachment)
                        <a href="/read/{{ $message->getMessageNo() }}/attachment/{{ $part }}"><i class="glyphicon glyphicon-download-alt"></i> {{ $attachment->getFilename() }}</a><br/>
                    @endforeach
                @endif                            
                </div>
            </div>
        </div>
    </div>
</div>

@stop