<!DOCTYPE html>
<html>
  <head>
     <style type="text/css">
     table, tr, td {
        border: 1px solid black;
        border-collapse: collapse;
        padding: 3px;
     }
     </style>
     <title>Create Table</title>
  </head>
  <body>
  <?php
  function create_table($data) {
     echo '<table>';
     reset($data);
     $value = current($data);
     while ($value) {
        echo "<tr><td>$value</td></tr>\n";
        $value = next($data);
     }
     echo '</table>';
   }
  
   $my_data = ['First piece of data','Second piece of data','And the third'];
   create_table($my_data);
   ?>
   </body>
</html>
