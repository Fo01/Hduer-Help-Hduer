<?php
$old_max_execution_time = ini_set('max_execution_time', 120);
echo 'old timeout is '.$old_max_execution_time.'<br />';

$max_execution_time = ini_get('max_execution_time');
echo 'new timeout is '.$max_execution_time.'<br />';
?>
