<? 
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);
	$id = $_REQUEST['id'];

	$todays_date = todays_date();
	$sql = "SELECT title,body FROM article WHERE id = $id";
	$result = mysql_query($sql);
	list($title,$body) = mysql_fetch_array($result);
	$title = stripslashes($title);
	print "<h1>$title</h1>\n";
	$body = stripslashes($body);
	print preg_replace("/[\n\r]+/", "<p>", $body);
?>
