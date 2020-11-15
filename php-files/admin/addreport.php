<html>
<head>
<title> Bray Wanderers Results </title>
</head>

<body bgcolor="white" text="#00C000">
<basefont face="arial">

<? 
	function quote($arg1) {
		return ("'".preg_replace("'", "\\'", $arg1)."'");
	}
        include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

	if($_REQUEST['update']) {
		$game = $_REQUEST['game'];
		$columnist = $_REQUEST['columnist'];
		$article = $_REQUEST['article'];

		$sql = "INSERT INTO report VALUES ($game, $columnist, '".addslashes($article)."')";

		if(mysql_query($sql)) {
			print "<h1>Update succeeded</h1>";
		} else {
			print "<h1>Update failed</h1>";
			print "<h2>".mysql_error()."</h2>";
			print "<pre>$sql</pre>";
			phpinfo(INFO_VARIABLES);
		}
	}
?>

<form action="addreport.php" method="post">
<input type=hidden name=update value=yes>
<select name=columnist>
<?
	$sql = "seleCT id,name FROM columnist";
	$result = mysql_query($sql);
	while(list($id,$name) = mysql_fetch_array($result)) {
		print("<option value=$id>$name");
	}
?>
</select><p>
Game: <select name=game><?
	$sql = "select game.id,opponent.name,game.date,game.venue from game,opponent where game.opponents = opponent.id and game.date <= '".todays_date()."' ORDER BY game.date DESC";
	$game = $_REQUEST['game'];
	$result = mysql_query($sql);
	while(list($id, $name, $date, $venue) = mysql_fetch_array($result)) {
		if($name == "") { $name = "No opponent defined" ;}
		if($id == $game) {
			print "<option value=$id selected>$name <i>$venue</i> $date </option>\n";
		} else {
			print "<option value=$id>$name <i>$venue</i> $date </option>\n";
		}
	}
?></select>

Body:<br>
<textarea name="article" rows=40 cols=70>
</textarea><br>
<input type=submit value="Save report">
</form>
</table><p>
<p>
<a href=admingames.php> Back to main games page </a>
<br>
<a href=index.html>Back to main admin page </a>
</body>
</html>
