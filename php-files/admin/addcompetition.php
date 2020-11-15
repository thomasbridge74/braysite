<html>
<head>
<title>
Add opponent
</title>

<body>
<? 
        include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);
	$competition = $_REQUEST['competition'];
	
	$sql = "INSERT INTO competition VALUES (0, '$competition')";
	if(mysql_query($sql)) {
		print "$opponent added to DB";
	} else {
		print "Error in <pre>\n$sql</pre>";
		print mysql_error();
	}
?>

<p>
<a href=admingames.php?action=list> Back to Games Admin</a>
</body>
</html>
