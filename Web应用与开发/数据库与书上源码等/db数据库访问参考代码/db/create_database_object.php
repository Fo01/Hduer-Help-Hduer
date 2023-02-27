<?php
	//实例 (MySQLi - 面向对象)创建数据库连接
	echo "实例 (MySQLi - 面向对象)<br/>";
	$servername = "127.0.0.1";
	$username = "root";
	$password = "2020#_web_*dev";

	date_default_timezone_set("Asia/Shanghai");
	echo date('Y-m-d H:i:s',strtotime('now'));

	// 创建连接
	$conn = new mysqli($servername, $username, $password);

	// 检测连接
	if ($conn->connect_error) {
	    die("连接失败: " . $conn->connect_error);
	}

	// 创建数据库myDB
	$sql = "CREATE DATABASE myDB";
	if ($conn->query($sql) === TRUE) {
	    echo "数据库创建成功";
	} else {
	    echo "<mark><br/>Error creating database: " . $conn->error."</mark>";
	    echo "<br/>";
	}/*	注意： 当你创建一个新的数据库时，你必须为 mysqli 对象指定三个参数 (servername, username 和 password)。
Tip: 如果你使用其他端口（默认为3306），为数据库参数添加空字符串，指定端口号
如: new mysqli("localhost", "username", "password", "", port)*/

	echo "连接成功<br/>";
	$conn->close();//关闭连接
	echo "关闭连接<br/>";
?>
