<? 
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

	$todays_date = todays_date();
	$sql = "SELECT title,body FROM article WHERE id = 582";
	$result = mysql_query($sql);
	list($title,$body) = mysql_fetch_array($result);
	$title = stripslashes($title);
	print "<h1>$title</h1>\n";
	$body = stripslashes($body);
	print preg_replace("/[\n\r]+/", "<p>", $body);
	print "<table>";
	show_news('worldcup',$connection);
	print "</table>";
?>
