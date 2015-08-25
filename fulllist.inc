<?
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
	$columnist = $_REQUEST['columnist'];
        mysql_select_db($dbname, $connection);

	$sql = "SELECT name,description FROM columnist WHERE id = $columnist";
	$result = mysql_query($sql);
	list($name, $description) = mysql_fetch_array($result);
	$name = stripslashes($name);
	$description = stripslashes($description);
	print "<h1>$name</h1>\n<p>$description\n";
	$sql = "SELECT id,title FROM article WHERE columnist = $columnist";
	# print $sql;
	$result = mysql_query($sql);
?><ul><?
	while(list($id,$title) = mysql_fetch_array($result)) {
		$title = stripslashes($title);
		print "<li><a href=showarticle.php?id=$id>$title</a>\n";
	}
?>
</ul>
<p>
<a href=articles.php>Back</a>
