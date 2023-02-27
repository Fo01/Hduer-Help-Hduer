<?php

$printer =  function($value){ echo "$value <br/>"; };

$products = [ 'Tires' => 100, 
              'Oil' => 10,
              'Spark Plugs' => 4 ]; 

$markup = 0.20;

$apply = function(&$val) use ($markup) {
           $val = $val * (1+$markup);
         };

array_walk($products, $apply);

array_walk($products, $printer);

?>