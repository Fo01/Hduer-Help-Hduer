<!DOCTYPE html>
<html>
<head>
  <title>Book-O-Rama Search Results</title>
</head>
<body>
  <h1>Book-O-Rama Search Results</h1>
  <?php
    // create short variable names
    $searchtype=$_POST['searchtype'];
    $searchterm="%{$_POST['searchterm']}%";

    if (!$searchtype || !$searchterm) {
       echo '<p>You have not entered search details.<br/>
       Please go back and try again.</p>';
       exit;
    }

    // whitelist the searchtype
    switch ($searchtype) {
      case 'Title':
      case 'Author':
      case 'ISBN':   
        break;
      default: 
        echo '<p>That is not a valid search type. <br/>
        Please go back and try again.</p>';
        exit; 
    }

    $db = new mysqli('localhost', 'bookorama', 'bookorama123', 'books');
    if (mysqli_connect_errno()) {
       echo '<p>Error: Could not connect to database.<br/>
       Please try again later.</p>';
       exit;
    }

    $query = "SELECT ISBN, Author, Title, Price FROM Books WHERE $searchtype = ?";
    $stmt = $db->prepare($query);
    $stmt->bind_param('s', $searchterm);  
    $stmt->execute();
    $stmt->store_result();
  
    $stmt->bind_result($isbn, $author, $title, $price);

    echo "<p>Number of books found: ".$stmt->num_rows."</p>";

    while($stmt->fetch()) {
      echo "<p><strong>Title: ".$title."</strong>";
      echo "<br />Author: ".$author;
      echo "<br />ISBN: ".$isbn;
      echo "<br />Price: \$".number_format($price,2)."</p>";
    }

    $stmt->free_result();
    $db->close();
  ?>
</body>
</html>
