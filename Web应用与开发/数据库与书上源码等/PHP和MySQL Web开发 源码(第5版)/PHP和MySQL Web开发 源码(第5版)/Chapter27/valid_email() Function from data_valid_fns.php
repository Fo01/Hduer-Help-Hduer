function valid_email($address) {
  // check an email address is possibly valid
  if (preg_match('/^[a-zA-Z0-9_\.\-]+@[a-zA-Z0-9\-]+\.[a-zA-Z0-9\-\.]+$/', $address))
{
    return true;
  } else {
    return false;
  }
}