<?php
	//实例 (MySQLi 面向对象)创建表格
	date_default_timezone_set("Asia/Shanghai");
	echo date('Y-m-d H:i:s',strtotime('now'));
	echo "<br/>";

	$servername = "127.0.0.1";
	$username = "root";
	$password = "root";
	$dbname = "myDB";

	// 创建连接
	$conn = new mysqli($servername, $username, $password, $dbname);
	// 检测连接
	if ($conn->connect_error) {
	    die("连接失败: " . $conn->connect_error);
	}

	// 使用 sql 创建数据表MyGuests
	$sql = "CREATE TABLE MyGuests (
	id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
	firstname VARCHAR(30) NOT NULL,
	lastname VARCHAR(30) NOT NULL,
	email VARCHAR(50)
	)";

	echo "<mark>";
	if ($conn->query($sql) === TRUE) {
	    echo "Table MyGuests created successfully";
    }
    else {
	    echo "创建数据表错误: " . $conn->error;
	}
	echo "</mark>";

    $sql = "INSERT INTO MyGuests( `firstname`, `lastname`, `email`) VALUES ('Hangzhou', 'Zhejiang', 'hz@zj.com')";
    $conn->query($sql);

    printf ("New Record has id %d.\n", $conn->insert_id);


	//连接
	$conn->close();
?>
