<?php
session_start();

echo 'The content of $_SESSION[\'session_var\'] is '
     .$_SESSION['session_var'].'<br />';

unset($_SESSION['session_var']);
?>
<p><a href="page3.php">Next page</a></p>