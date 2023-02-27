<?php $__env->startSection('main'); ?>
<div class="col-lg-5 col-lg-offset-2">
    <div class="panel panel-default">
        <div class="panel-heading">
            Please Login
        </div>
        <div class="panel-body">
            <form action="/auth/login" method="POST">
                <?php echo csrf_field(); ?>

                <div class="form-group">
                    <label for="email">GMail Username</label>
                    <input type="text" name="email" id="email" placeholder="user@gmail.com">
                </div>
                <div class="form-group">
                    <label for="password">GMail Password</label>
                    <input type="password" name="password" id="password">
                </div>
                <div class="form-group">
                    <input type="checkbox" name="remember"> Remember Me
                </div>
                <button class="btn btn-block btn-primary" type="submit"><i class="glyphicon glyphicon-lock"></i> Login</button>
            </form>
        </div>
    </div>
</div>
<?php $__env->stopSection(); ?>
<?php echo $__env->make('layouts.public', array_except(get_defined_vars(), array('__data', '__path')))->render(); ?>