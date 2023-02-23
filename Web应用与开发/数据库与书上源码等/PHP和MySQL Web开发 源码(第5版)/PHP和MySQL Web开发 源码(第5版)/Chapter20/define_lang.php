<?php
if ((!isset($_SESSION['lang'])) || (!isset($_GET['lang']))) {
	$_SESSION['lang'] = "en";
	$currLang = "en";
} else {
	$currLang = $_GET['lang'];
	$_SESSION['lang'] = $currLang;
}

switch($currLang) {
	case "en":
		define("CHARSET","ISO-8859-1");
		define("LANGCODE", "en");
	break;

	case "ja":
		define("CHARSET","UTF-8");
		define("LANGCODE", "ja");
	break;

	default:
		define("CHARSET","ISO-8859-1");
		define("LANGCODE", "en");
	break;
}

header("Content-Type: text/html;charset=".CHARSET);
header("Content-Language: ".LANGCODE);
?>
