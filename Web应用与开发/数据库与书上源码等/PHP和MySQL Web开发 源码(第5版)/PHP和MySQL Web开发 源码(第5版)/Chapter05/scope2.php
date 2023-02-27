<?php
function fn() {
  global $var;
  $var = 'contents';
  echo 'inside the function, $var = '.$var.'<br />';
}

fn();
echo 'outside the function, $var = '.$var;
?>