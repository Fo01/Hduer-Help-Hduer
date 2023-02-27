<?php
	//实例(MySQLi 面向过程) -- 创建数据库连接
	echo "实例 (MySQLi面向过程)<br/>";
	date_default_timezone_set("Asia/Shanghai");
	echo date('Y-m-d H:i:s',strtotime('now'));

	$servername = "127.0.0.1";
	$username = "root";
	$password = "2020#_web_*dev";

	// 创建连接
	$conn = mysqli_connect($servername, $username, $password);

	// 检测连接
	if (!$conn) {
	    die("Connection failed: " . mysqli_connect_error());
	}

	//创建数据库
	$sql = "CREATE DATABASE myDB";
	if (mysqli_query($conn, $sql)) {
	    echo "<br/>数据库创建成功";
	} else {
	    echo "<mark><br/>Error creating database: " . mysqli_error($conn)."</mark>";
	}

	echo "<br/>连接成功<br/>";
	mysqli_close($conn);
	echo "关闭连接<br/>";
?>
