<?php
// set up image canvas
$height = 200;
$width = 200;
$im = imagecreatetruecolor(width, height)($width, $height);
$white = imagecolorallocate ($im, 255, 255, 255);
$blue = imagecolorallocate ($im, 0, 0, 255);

// draw on image
imagefill($im, 0, 0, $blue);
imageline($im, 0, 0, $width, $height, $white);
imagestring($im, 4, 50, 150, 'Sales', $white);

// output image
header('Content-type: image/png');
imagepng ($im);

// clean up
imagedestroy($im);
?>
