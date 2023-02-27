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
                <ul class="messages">
                    
                    <?php foreach($messages as $message): ?>
                    <li>
                        <a href="/read/<?php echo e($message->getMessageNo()); ?>" class="nohover">
                            <div class="header">
                                <span class="from">
                                    <?php echo e($message->getFrom()); ?>

                                    <span class="pull-right">
                                        <?php echo e($message->getDate()->format('F jS, Y h:i A')); ?>

                                    </span>
                                </span>
                                <?php echo e($message->getSubject()); ?>

                            </div>
                        </a>
                        <hr/>
                    </li>
                    <?php endforeach; ?>
                </ul>
            </div>
        </div>
        <div class="text-center">
            <?php echo e($paginator->render()); ?>

        </div>
    </div>
</div>
<?php $__env->stopSection(); ?>
<?php echo $__env->make('layouts.authed', array_except(get_defined_vars(), array('__data', '__path')))->render(); ?>