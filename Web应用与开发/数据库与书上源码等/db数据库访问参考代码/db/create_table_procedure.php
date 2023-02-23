<?php
	//实例 (MySQLi 面向过程)创建数据库连接
	date_default_timezone_set("Asia/Shanghai");
	echo date('Y-m-d H:i:s',strtotime('now'));
	echo "<br/>";

	$servername = "127.0.0.1";
	$username = "root";
	$password = "2020#_web_*dev";
	$dbname = "myDB";

	// 创建连接
	$conn = mysqli_connect($servername, $username, $password, $dbname);
	// 检测连接
	if (!$conn) {
		echo "<mark>";
		die("连接失败: " . mysqli_connect_error());
		echo "</mark>";
	}

	// 使用 sql 创建数据表MyGuests
	$sql = "CREATE TABLE MyGuests (
		id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
		firstname VARCHAR(30) NOT NULL,
		lastname VARCHAR(30) NOT NULL,
		email VARCHAR(50),
		reg_date TIMESTAMP
	)";
	echo "<mark>";

	if (mysqli_query($conn, $sql)) {
		echo "数据表 MyGuests 创建成功";
	} else {
		echo "创建数据表错误: " . mysqli_error($conn);
	}	echo "</mark>";

	mysqli_close($conn);
?>
