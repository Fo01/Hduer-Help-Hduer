<!DOCTYPE html>
<html>
<head>
  <title>File Details</title>
</head>
<body>
<?php
  
  if (!isset($_GET['file'])) 
  {
     echo "You have not specified a file name.";
  } 
  else {
     $uploads_dir = '/path/to/uploads/';
     $the_file = basename($_GET['file']);  // strip off directory information for security

     $safe_file = $uploads_dir.$the_file;

     echo '<h1>Details of File: '.$the_file.'</h1>';

     echo '<h2>File Data</h2>';
     echo 'File Last Accessed: '.date('j F Y H:i', fileatime($safe_file)).'<br/>';
     echo 'File Last Modified: '.date('j F Y H:i', filemtime($safe_file)).'<br/>';

     $user = posix_getpwuid(fileowner($safe_file));
     echo 'File Owner: '.$user['name'].'<br/>';
  
     $group = posix_getgrgid(filegroup($safe_file));
     echo 'File Group: '.$group['name'].'<br/>';

     echo 'File Permissions: '.decoct(fileperms($safe_file)).'<br/>';
     echo 'File Type: '.filetype($safe_file).'<br/>';
     echo 'File Size: '.filesize($safe_file).' bytes<br>';

     echo '<h2>File Tests</h2>';
     echo 'is_dir: '.(is_dir($safe_file)? 'true' : 'false').'<br/>';
     echo 'is_executable: '.(is_executable($safe_file)? 'true' : 'false').'<br/>';
     echo 'is_file: '.(is_file($safe_file)? 'true' : 'false').'<br/>';
     echo 'is_link: '.(is_link($safe_file)? 'true' : 'false').'<br/>';
     echo 'is_readable: '.(is_readable($safe_file)? 'true' : 'false').'<br/>';
     echo 'is_writable: '.(is_writable($safe_file)? 'true' : 'false').'<br/>';
  }
?>
</body>
</html>
