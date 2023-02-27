<?php $__env->startSection('stylesheets'); ?>
@parent
<link href="/css/app.css" rel="stylesheet"/>
<?php $__env->stopSection(); ?>

<?php $__env->startSection('main'); ?>
<div class="row">
    <div class="col-md-3">
        <div class="text-center"><h2>Mailboxes</h2></div>
        <div class="panel panel-default">
            <div class="panel-body">
                <a href="/compose" class="btn btn-primary btn-block">Compose</a>
                <ul class="folders">
                    <?php foreach($mailboxes as $mailbox): ?>
                    <li>
                        <a href="/inbox?box=<?php echo e($mailbox); ?>"><i class="glyphicon glyphicon-inbox"></i> <?php echo e($mailbox); ?></a>
                    </li>
                    <?php endforeach; ?>
                </ul>
            </div>
        </div>
    </div>
    
    <div class="col-md-9">
    
    <div class="text-center">
        <?php if(is_null($message)): ?>
        <h2>Webmail Demo - Compose</h2>
        <?php else: ?>
        <h2>Webmail Demo - Reply</h2>
        <?php endif; ?>
    </div>
        <div class="panel panel-default">
            <div class="panel-body">
                <form action="/compose/send" method="post">
                    <?php echo csrf_field(); ?>

                    <div class="header">
                        <?php if(!is_null($message)): ?>
                            <span class="from">
                                From: <input class="form-control" type="text" name="from" value="<?php echo e($message->getToEmail()); ?>"/>
                            </span>
                            <span class="to">
                                To: <input class="form-control" type="text" name="to" value="<?php echo e($message->getFromEmail()); ?>"/>
                            </span>
                            <span class="subject">
                                Subject: <input type="text" class="form-control" name="subject" value="RE: <?php echo e($message->getSubject()); ?>"/>
                            </span>
                        <?php else: ?>
                            <span class="from">
                                From: <input type="text" name="from" value="" class="form-control"/>
                            </span>
                            <span class="to">
                                To: <input class="form-control" type="text" name="to" value=""/>
                            </span>
                            <span class="subject">
                                Subject: <input type="text" name="subject" value="" class="form-control"/>
                            </span>
                        <?php endif; ?>
                    </div>
                    <hr/>
                    <div class="messageBody">
                    <textarea class="form-control replybox" name="message" rows="10" ><?php echo e($quotedMessage); ?></textarea>
                    </div>
                    <hr/>
                    <input type="submit" class="btn btn-block btn-primary" value="Send E-mail"/>
                </form>
            </div>
        </div>
    </div>
</div>

<?php $__env->stopSection(); ?>
<?php echo $__env->make('layouts.authed', array_except(get_defined_vars(), array('__data', '__path')))->render(); ?>