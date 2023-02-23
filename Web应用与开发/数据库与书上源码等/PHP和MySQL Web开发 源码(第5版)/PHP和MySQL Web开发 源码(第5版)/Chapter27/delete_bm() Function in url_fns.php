function delete_bm($user, $url) {
  // delete one URL from the database
  $conn = db_connect();

  // delete the bookmark
  if (!$conn->query("delete from bookmark where
                    username='".$user."'
                    and bm_url='".$url."'")) {
     throw new Exception('Bookmark could not be deleted');
  }
  return true;
}