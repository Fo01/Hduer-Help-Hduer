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
    <div class="text-center"><h2>Webmail Demo - <?php echo e($currentMailbox); ?></h2></div>
        <div class="panel panel-default">
            <div class="panel-body">
                <div class="header">
                    <span class="from">
                        <?php echo e($message->getFrom()); ?>

                    </span>
                    <span class="subject">
                        <?php echo e($message->getSubject()); ?>

                        <span class="date">
                            <?php echo e($message->getDate()->format('F jS, Y')); ?>

                        </span>
                    </span>
                </div>
                <hr/>
                <div class="btn-group pull-right">
                    <a href="/compose/<?php echo e($message->getMessageNo()); ?>" class="btn btn-default"><i class="glyphicon glyphicon-envelope"></i> Reply</a>
                    <a href="/inbox/delete/<?php echo e($message->getMessageNo()); ?>" class="btn btn-default"><i class="glyphicon glyphicon-trash"></i> Delete</a>
                </div>
                <div class="messageBody">
                <?php echo e($message); ?>

                <?php if(!empty($message->getAttachments())): ?>
                    <hr/>
                    <?php foreach($message->getAttachments() as $part => $attachment): ?>
                        <a href="/read/<?php echo e($message->getMessageNo()); ?>/attachment/<?php echo e($part); ?>"><i class="glyphicon glyphicon-download-alt"></i> <?php echo e($attachment->getFilename()); ?></a><br/>
                    <?php endforeach; ?>
                <?php endif; ?>                            
                </div>
            </div>
        </div>
    </div>
</div>

<?php $__env->stopSection(); ?>
<?php echo $__env->make('layouts.authed', array_except(get_defined_vars(), array('__data', '__path')))->render(); ?>