<!DOCTYPE html>
<html>
<head>
   <title>Stock Quote From NASDAQ</title>
</head>
<body>

<?php
//choose stock to look at
$symbol = 'GOOG';
echo '<h1>Stock Quote for '.$symbol.'</h1>';

$url = 'http://download.finance.yahoo.com/d/quotes.csv' .
    '?s='.$symbol.'&e=.csv&f=sl1d1t1c1ohgv';

if (!($contents = file_get_contents($url))) {
    die('Failed to open '.$url);
}

// extract relavant data
list($symbol, $quote, $date, $time) = explode(',', $contents);
$date = trim($date, '"');
$time = trim($time, '"');

echo '<p>'.$symbol.' was last sold at: $'.$quote.'</p>';
echo '<p>Quote current as of '.$date.' at '.$time.'</p>';

// acknowledge source
echo '<p>This information retrieved from <br /><a href="'.$url.'">'.$url.'</a>.</p>';

?>
</body>
</html>
