<html>
<head>
<title>Delete Story </title>
</head>
<body>

<?
	include("functions.inc");
	$action = $_REQUEST['action'];
	$id = $_REQUEST['id'];
	
	if($action == 'confirm') {
		$connection = mysql_connect($dbserver, $dbuser, $dbpass);
		mysql_select_db($dbname, $connection);
		delete_news_item($id, $connection);
	} else {
		?>
		<form action=delnews.php method=post>
		<input type=hidden name=action value=confirm>
		<input type=hidden name=id value=<?echo $id?>>
		<input type=submit value="Delete this item">
		<?
	}

?>
<p>
<a href=news-admin.php>Back to News Admin</a>
</body>
</html>
		
