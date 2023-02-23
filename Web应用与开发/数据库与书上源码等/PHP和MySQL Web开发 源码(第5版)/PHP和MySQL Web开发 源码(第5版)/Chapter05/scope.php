<?php
function fn() {
  echo 'inside the function, at first $var = '.$var.'<br />';
  $var = 2;
  echo 'then, inside the function, $var = '.$var.'<br />';
}
$var = 1;
fn();
echo 'outside the function, $var = '.$var.'<br />';
?>