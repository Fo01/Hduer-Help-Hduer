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
                <ul class="messages">
                    
                    @foreach($messages as $message)
                    <li>
                        <a href="/read/{{ $message->getMessageNo() }}" class="nohover">
                            <div class="header">
                                <span class="from">
                                    {{{ $message->getFrom() }}}
                                    <span class="pull-right">
                                        {{{ $message->getDate()->format('F jS, Y h:i A') }}}
                                    </span>
                                </span>
                                {{{ $message->getSubject() }}}
                            </div>
                        </a>
                        <hr/>
                    </li>
                    @endforeach
                </ul>
            </div>
        </div>
        <div class="text-center">
            {{ $paginator->render() }}
        </div>
    </div>
</div>
@stop