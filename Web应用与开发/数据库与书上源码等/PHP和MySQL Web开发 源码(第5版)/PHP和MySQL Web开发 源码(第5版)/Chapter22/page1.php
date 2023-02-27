<?php
session_start();

$_SESSION['session_var'] = "Hello world!";

echo 'The content of $_SESSION[\'session_var\'] is '
     .$_SESSION['session_var'].'<br />';
?>
<p><a href="page2.php">Next page</a></p>