<?php
session_start();

echo 'The content of $_SESSION[\'session_var\'] is '
     .$_SESSION['session_var'].'<br />';

session_destroy();
?>