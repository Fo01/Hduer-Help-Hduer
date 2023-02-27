function check_valid_user() {
// see if somebody is logged in and notify them if not
  if (isset($_SESSION['valid_user']))  {
      echo "Logged in as ".$_SESSION['valid_user'].".<br>";
  } else {
     // they are not logged in
     do_html_heading('Problem:');
     echo 'You are not logged in.<br>';
     do_html_url('login.php', 'Login');
     do_html_footer();
     exit;
  }
}