<!DOCTYPE html>
<html>
<head>
   <title>Browse Directories</title>
</head>
<body>
   <h1>Browsing</h1>

<?php
  $current_dir = '/path/to/uploads/';
  $dir = opendir($current_dir);

  echo '<p>Upload directory is '.$current_dir.'</p>';
  echo '<p>Directory Listing:</p><ul>';
  
  while(false !== ($file = readdir($dir)))
  {
    //strip out the two entries of . and ..
    if($file != "." && $file != "..")
       {
         echo '<li><a href="filedetails.php?file='.$file.'">'.$file.'</a></li>';
       }
  }
  echo '</ul>';
  closedir($dir);
?>

</body>
</html>