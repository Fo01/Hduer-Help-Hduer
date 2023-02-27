<?php
// Check we have the appropriate variable data 
// (the variables are button-text and button-color)

$button_text = $_POST['button_text'];
$button_color = $_POST['button_color'];

if (empty($button_text) || empty($button_color))
{
  echo '<p>Could not create image: form not filled out correctly.</p>';
  exit;
}

// Create an image using the right color of button, and check the size
$im = imagecreatefrompng($button_color.'-button.png');

$width_image = imagesx($im);
$height_image = imagesy($im);

// Our images need an 18 pixel margin in from the edge of the image
$width_image_wo_margins = $width_image - (2 * 18);
$height_image_wo_margins = $height_image - (2 * 18);

// Tell GD2 where the font you want to use resides

// For Windows, use:
// putenv('GDFONTPATH=C:\WINDOWS\Fonts'); 

// For UNIX, use the full path to the font folder.
// In this example we're using the DejaVu font family:
putenv('GDFONTPATH=/usr/share/fonts/truetype/dejavu'); 

$font_name = 'DejaVuSans';

// Work out if the font size will fit and make it smaller until it does 
// Start out with the biggest size that will reasonably fit on our buttons
$font_size = 33;

do
{
  $font_size--;

  // Find out the size of the text at that font size
  $bbox = imagettfbbox($font_size, 0, $font_name, $button_text);

  $right_text = $bbox[2]; // right co-ordinate
  $left_text = $bbox[0];  // left co-ordinate
  $width_text = $right_text - $left_text;   // how wide is it?
  $height_text = abs($bbox[7] - $bbox[1]);  // how tall is it?
   
} while ($font_size > 8 &&
       ($height_text > $height_image_wo_margins ||
        $width_text > $width_image_wo_margins)
      );

if ($height_text > $height_image_wo_margins ||
     $width_text > $width_image_wo_margins) 
{
  // no readable font size will fit on button
  echo '<p>Text given will not fit on button.</p>';
} 
else
{
  // We have found a font size that will fit.
  // Now work out where to put it.

  $text_x = $width_image / 2.0 - $width_text / 2.0;
  $text_y = $height_image / 2.0 - $height_text / 2.0 ;

  if ($left_text < 0)
  {
    $text_x += abs($left_text);     // add factor for left overhang
  }

  $above_line_text = abs($bbox[7]); // how far above the baseline?
  $text_y += $above_line_text;      // add baseline factor 
  
  $text_y -= 2;  // adjustment factor for shape of our template

  $white = imagecolorallocate ($im, 255, 255, 255);

  imagettftext ($im, $font_size, 0, $text_x, $text_y, $white, 
                $font_name, $button_text);

  header('Content-type: image/png');
  imagepng ($im);
}

// Clean up the resources 
imagedestroy ($im);
?>
