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

    // set up for using PDO
    $user = 'bookorama';
    $pass = 'bookorama123';
    $host = 'localhost';
    $db_name = 'books';

    // set up DSN
    $dsn = "mysql:host=$host;dbname=$db_name";

    // connect to database
    try {
      $db = new PDO($dsn, $user, $pass); 

      // perform query
      $query = "SELECT ISBN, Author, Title, Price FROM Books WHERE $searchtype like :searchterm";  
      $stmt = $db->prepare($query);  
      $stmt->bindParam(':searchterm', $searchterm);
      $stmt->execute(); 

      // get number of returned rows  
      echo "<p>Number of books found: ".$stmt->rowCount()."</p>"; 

      // display each returned row
      while($result = $stmt->fetch(PDO::FETCH_OBJ)) {                                                       
        echo "<p><strong>Title: ".$result->Title."</strong>";                               
        echo "<br />Author: ".$result->Author;                                              
        echo "<br />ISBN: ".$result->ISBN;                                                  
        echo "<br />Price: \$".number_format($result->Price, 2)."</p>";                                         
      }         

      // disconnect from database
      $db = NULL;
    } catch (PDOException $e) {
      echo "Error: ".$e->getMessage();
      exit;
    }
  ?>
</body>
</html>
