<?php
echo 'Function sets supported in this install are: <br />';
$extensions = get_loaded_extensions();
foreach ($extensions as $each_ext)
{
  echo $each_ext.'<br />';
  echo '<ul>';
  $ext_funcs = get_extension_funcs($each_ext);
  foreach($ext_funcs as $func)
  {
    echo '<li>'.$func.'</li>';
  }
  echo '</ul>';
}
?>
