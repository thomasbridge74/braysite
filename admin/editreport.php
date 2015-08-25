<html>
<head>
<title>
Games edit page
</title>
</head>

<body>
<?
	include("functions.inc");
	$connection = mysql_connect($dbserver, $dbuser, $dbpass);
	mysql_select_db($dbname, $connection);
	$game = $_REQUEST['game'];
	$columnist = $_REQUEST['columnist'];
	if($_REQUEST['update']) {
		$oldgame = $_REQUEST['oldgame'];
		$oldcolumnist = $_REQUEST['oldcolumnist'];
		$body = addslashes($_REQUEST['body']);

		$sql = "UPDATE report SET game = $game, columnist = $columnist, body = '$body' WHERE game = $oldgame AND columnist = $oldcolumnist";
		if(mysql_query($sql)) {
			print "Update made";
		} else {
			print "Update failed: ".mysql_error();
			print "<pre>$sql</pre>";
			phpinfo(INFO_VARIABLES);
		}
	}
?>
<form action=editreport.php method=post>
<input type=hidden name=update value=wibble>
<input type=hidden name=oldgame value=<? echo $game; ?>>
<input type=hidden name=oldcolumnist value=<? echo $columnist; ?>>

<?
	$sql = "SELECT body FROM report WHERE game = $game AND columnist = $columnist";
	$result = mysql_query($sql);

	list($body) = mysql_fetch_array($result);
	$body = stripslashes($body);
	game_menu($game, $connection);
	columnist_menu($columnist, $connection);
?>

<p>
<textarea name=body rows=40 cols=70>
<? echo $body ?>
</textarea>
<br>
<input type=submit>

<p>
<a href=admingames.php> Back to main games page </a>
<br>
<a href=index.html>Back to main admin page </a>
</body>
</html>
