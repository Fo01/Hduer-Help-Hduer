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
    
    <div class="text-center">
        @if(is_null($message))
        <h2>Webmail Demo - Compose</h2>
        @else
        <h2>Webmail Demo - Reply</h2>
        @endif
    </div>
        <div class="panel panel-default">
            <div class="panel-body">
                <form action="/compose/send" method="post">
                    {!! csrf_field() !!}
                    <div class="header">
                        @if(!is_null($message))
                            <span class="from">
                                From: <input class="form-control" type="text" name="from" value="{{ $message->getToEmail() }}"/>
                            </span>
                            <span class="to">
                                To: <input class="form-control" type="text" name="to" value="{{ $message->getFromEmail() }}"/>
                            </span>
                            <span class="subject">
                                Subject: <input type="text" class="form-control" name="subject" value="RE: {{{ $message->getSubject() }}}"/>
                            </span>
                        @else
                            <span class="from">
                                From: <input type="text" name="from" value="" class="form-control"/>
                            </span>
                            <span class="to">
                                To: <input class="form-control" type="text" name="to" value=""/>
                            </span>
                            <span class="subject">
                                Subject: <input type="text" name="subject" value="" class="form-control"/>
                            </span>
                        @endif
                    </div>
                    <hr/>
                    <div class="messageBody">
                    <textarea class="form-control replybox" name="message" rows="10" >{{{ $quotedMessage }}}</textarea>
                    </div>
                    <hr/>
                    <input type="submit" class="btn btn-block btn-primary" value="Send E-mail"/>
                </form>
            </div>
        </div>
    </div>
</div>

@stop