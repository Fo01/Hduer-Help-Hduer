<?php

function var_args() {
  echo 'Number of parameters:';
  echo func_num_args();

  echo '<br />';
  $args = func_get_args();
  foreach ($args as $arg) {
    echo $arg.'<br />';
  }
}

var_args(1,2,3);

var_args('hello', 47.3);

?>
