<?php
session_start();
include 'define_lang.php';
include 'lang_strings.php';
defineStrings();
?>
<!DOCTYPE html>
<html lang="<?php echo LANGCODE; ?>">
   <title><?php echo WELCOME_TXT; ?></title>
   <meta charset="<?php echo CHARSET; ?>" />
<body>
   <h1><?php echo WELCOME_TXT; ?></h1>
   <h2><?php echo CHOOSE_TXT; ?></h2>
   <ul>
      <li><a href="<?php echo $_SERVER['PHP_SELF']."?lang=en"; ?>">en</a></li>
      <li><a href="<?php echo $_SERVER['PHP_SELF']."?lang=ja"; ?>">ja</a></li> 
   </ul>
</body>
</html>
