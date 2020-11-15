<?
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

	$id = $_REQUEST['id'];

	$sql = "SELECT date, headline, details, category FROM news WHERE id = $id";
	$result = mysql_query($sql);
	list($date, $headline, $details, $category) = mysql_fetch_array($result);
	$headline = stripslashes($headline);
	print "<h2> $headline </h2>";
	print "<h3> $date </h3>";
	print "<p>";
	$details = stripslashes($details);
	print  preg_replace("/[\n\r]+/", "<p>", $details);
	print "<p><a href=news.php>Return to news index</a>";

?>
