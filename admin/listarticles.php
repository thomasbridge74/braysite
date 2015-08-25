<html>
<head>
<title>Article Listing</title>
</head>

<body>
<h1><a href=addarticle.php>Add a new article</a></h1>
<table>
<?
	include("functions.inc");
	$connection = mysql_connect($dbserver, $dbuser, $dbpass);
	mysql_selectdb($dbname, $connection);
	$columnistid = $_REQUEST['columnistid'];
	if($columnistid) {
		$sql = "SELECT article.id,columnist.name,article.title FROM article,columnist WHERE columnist.id = article.columnist AND columnist.id = $columnistid ORDER BY article.id";
		# print "<pre>$sql</pre>";
		$result = mysql_query($sql);
		while(list($id, $name, $title) = mysql_fetch_array($result)) {
			$name = stripslashes($name);
			$title = stripslashes($title);
			print "<tr><td><a href=addarticle.php?action=edit&edit=$id>$id</a></td><td>$name</td><td>$title</td></tr>\n";
		}
	} else {
		$sql = "SELECT id,name FROM columnist";
		# print "<pre>$sql</pre>";
		print "<form action=$PHP_SELF>";
		$result = mysql_query($sql);
		print "<select name=columnistid>";
		while(list($id,$name) = mysql_fetch_array($result)) {
			print "<option value=$id>$name\n";
		}
		print "</select><input type=submit value=\"Select Columnist\">\n</form>\n";
	}
?>
</table>

<a href=index.html>Back to admin menu</a>
</body>
</html>
