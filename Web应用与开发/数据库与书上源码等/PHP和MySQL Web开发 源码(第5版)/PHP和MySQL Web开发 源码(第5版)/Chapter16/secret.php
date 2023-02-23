<!DOCTYPE html>
<html>
<head>
   <title>Secret Page</title>
</head>
<body>

<?php
  if ((!isset($_POST['name'])) || (!isset($_POST['password']))) {
  // visitor needs to enter a name and password
?>
    <h1>Please Log In</h1>
    <p>This page is secret.</p>
    <form method="post" action="secret.php">
    <p><label for="name">Username:</label> 
    <input type="text" name="name" id="name" size="15" /></p>
    <p><label for="password">Password:</label> 
    <input type="password" name="password" id="password" size="15" /></p>
    <button type="submit" name="submit">Log In</button>    
    </form>
<?php
  } else if(($_POST['name']=='user') && ($_POST['password']=='pass')) {
    // visitor's name and password combination are correct
    echo '<h1>Here it is!</h1>
          <p>I bet you are glad you can see this secret page.</p>';
  } else {
    // visitor's name and password combination are not correct
    echo '<h1>Go Away!</h1>
          <p>You are not authorized to use this resource.</p>';
  }
?>
</body>
</html>