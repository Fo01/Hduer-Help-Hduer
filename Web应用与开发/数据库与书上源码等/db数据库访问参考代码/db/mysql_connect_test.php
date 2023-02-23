<?php
    $link = mysqli_connect("127.0.0.1", "root", "2020#_web_*dev", "mysql");

    if (!$link) {
        echo "Error: Unable to connect to MySQL." . PHP_EOL;
        echo "Debugging errno: " . mysqli_connect_errno() . PHP_EOL;
        echo "Debugging error: " . mysqli_connect_error() . PHP_EOL;
        exit;
    }

    echo "Success: A proper connection to MySQL was made!" . PHP_EOL;
    echo "Host information: " . mysqli_get_host_info($link) . PHP_EOL;

    mysqli_close($link);
?>
