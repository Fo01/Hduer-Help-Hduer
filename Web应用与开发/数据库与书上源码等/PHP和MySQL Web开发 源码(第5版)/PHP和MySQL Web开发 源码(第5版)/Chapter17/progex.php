<?php

chdir('/path/to/uploads/');

// exec version
echo '<h1>Using exec()</h1>';
echo '<pre>';

// unix
exec('ls -la', $result);

// windows
// exec('dir', $result);

foreach ($result as $line)
{
   echo $line.PHP_EOL;
}

echo '</pre>';
echo '<hr />';

// passthru version
echo '<h1>Using passthru()</h1>';
echo '<pre>';

// unix
passthru('ls -la') ;

// windows
// passthru('dir');

echo '</pre>';
echo '<hr />';

// system version
echo '<h1>Using system()</h1>';
echo '<pre>';

// unix
$result = system('ls -la');

// windows
// $result = system('dir');

echo '</pre>';
echo '<hr />';

// backticks version
echo '<h1>Using Backticks</h1>';
echo '<pre>';

// unix
$result = `ls -al`;

// windows 
// $result = `dir`;

echo $result;
echo '</pre>';

?>
