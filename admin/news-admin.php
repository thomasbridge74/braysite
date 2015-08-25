<html>
<head>
<title>Bray Wanderers News</title>
</head>

<body bgcolor=white text=black>
<basefont face="Arial,Helvectica">

<h1> Edit news from the club </h1>

<table>
<?
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);
	$archive = $_REQUEST['archive'];

	if($archive == "full") {
		$sql = "SELECT id, category, headline,date FROM news ORDER BY date DESC";
	} else {
		$sql = "SELECT id, category, headline FROM news WHERE expire > '".todays_date()."' ORDER BY date DESC";
	}
	$result = mysql_query($sql);
	while(list($id, $category, $headline) = mysql_fetch_array($result)) {
		print "<tr><td>$category</td><td><a href=addnews.php?action=edit&edit=$id>$headline</a></td></tr>\n";
	}

?>
</table><p>
<a href=addnews.php>Add a new story</a><br>
<a href=news-admin.php?archive=full>Full Archive</a><p>

<a href=index.html>Back to main Admin page</a>

</body>
</html>
