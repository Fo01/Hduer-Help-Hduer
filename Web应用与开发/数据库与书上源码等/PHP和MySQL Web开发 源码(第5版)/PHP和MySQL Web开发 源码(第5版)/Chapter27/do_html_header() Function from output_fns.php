function do_html_header($title) {
  // print an HTML header
?>
<!doctype html>
  <html>
  <head>
    <meta charset="utf-8">
    <title><?php echo $title;?></title>
    <style>
      body { font-family: Arial, Helvetica, sans-serif; font-size: 13px }
      li, td { font-family: Arial, Helvetica, sans-serif; font-size: 13px }
      hr { color: #3333cc;}
      a { color: #000 }
      div.formblock
         { background: #ccc; width: 300px; padding: 6px; border: 1px solid #000;}
    </style>
  </head>
  <body>
  <div>
    <img src="bookmark.gif" alt="PHPbookmark logo" height="55" width="57"
style="float: left; padding-right: 6px;" />
      <h1>PHPbookmark</h1>
  </div>
  <hr />
<?php
  if($title) {
    do_html_heading($title);
  }
}