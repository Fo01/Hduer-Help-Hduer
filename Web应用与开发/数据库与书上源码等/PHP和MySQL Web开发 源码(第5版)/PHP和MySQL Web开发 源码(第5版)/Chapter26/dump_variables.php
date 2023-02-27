<?php
start_session();

  // these lines format the output as HTML comments
  // and call dump_array repeatedly

  echo "\n<!-- BEGIN VARIABLE DUMP -->\n\n";

  echo "<!-- BEGIN GET VARS -->\n";
  echo "<!-- ".dump_array($_GET)." -->\n";

  echo "<!-- BEGIN POST VARS -->\n";
  echo "<!-- ".dump_array($_POST)." -->\n";

  echo "<!-- BEGIN SESSION VARS -->\n";
  echo "<!-- ".dump_array($_SESSION)." -->\n";

  echo "<!-- BEGIN COOKIE VARS -->\n";
  echo "<!-- ".dump_array($_COOKIE)." -->\n";

  echo "\n<!-- END VARIABLE DUMP -->\n";

// dump_array() takes one array as a parameter
// It iterates through that array, creating a single
// line string to represent the array as a set

function dump_array($array) {

  if(is_array($array)) {

    $size = count($array);
    $string = "";
    if($size) {

      $count = 0;
      $string .= "{ ";
      // add each element's key and value to the string
      foreach($array as $var => $value) {

        $string .= $var." = ".$value;
        if($count++ < ($size-1)) {
          $string .= ", ";
        }
      }
      $string .= " }";
    }
    return $string;
  } else {
    // if it is not an array, just return it
    return $array;
  }
}
?>
