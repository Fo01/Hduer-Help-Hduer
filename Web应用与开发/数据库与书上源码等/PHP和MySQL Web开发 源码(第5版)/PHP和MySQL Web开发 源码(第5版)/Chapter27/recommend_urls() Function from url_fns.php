function recommend_urls($valid_user, $popularity = 1) {
  // We will provide semi intelligent recommendations to people
  // If they have an URL in common with other users, they may like
  // other URLs that these people like
  $conn = db_connect();

  // find other matching users
  // with an url the same as you
  // as a simple way of excluding people's private pages, and
  // increasing the chance of recommending appealing URLs, we
  // specify a minimum popularity level
  // if $popularity = 1, then more than one person must have
  // an URL before we will recommend it

  $query = "select bm_URL
            from bookmark
            where username in
              (select distinct(b2.username)
               from bookmark b1, bookmark b2
               where b1.username='".$valid_user."'
               and b1.username != b2.username
               and b1.bm_URL = b2.bm_URL)
            and bm_URL not in
               (select bm_URL
                from bookmark
                where username='".$valid_user."')
            group by bm_url
            having count(bm_url)>".$popularity;

  if (!($result = $conn->query($query))) {
     throw new Exception('Could not find any bookmarks to recommend.');
  }

  if ($result->num_rows==0) {
     throw new Exception('Could not find any bookmarks to recommend.');
  }

  $urls = array();
  // build an array of the relevant urls
  for ($count=0; $row = $result->fetch_object(); $count++) {
     $urls[$count] = $row->bm_URL;
  }

  return $urls;
}