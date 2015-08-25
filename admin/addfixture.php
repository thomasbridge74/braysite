<html>
<head>
<title>
Add Fixture
</title>
</head>
<?
	include("functions.inc");
?>
<body>
<?
	function print_options($start, $end) {
		for($i = $start; $i <= $end; $i++){
			print "<option>$i";
		}
	}
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

   	if($_REQUEST['update']) {
		$opponents = $_REQUEST['opponents'];
		$venue = $_REQUEST['venue'];
		$year = $_REQUEST['year'];
		$mon = $_REQUEST['mon'];
		$date = $_REQUEST['date'];
		$season = $_REQUEST['season'];
		$competition = $_REQUEST['competition'];
		$squad = $_REQUEST['squad'];

		$sql = "INSERT INTO game (opponents, venue, date, season, competition, squad) VALUES ($opponents, '$venue', '$year-$mon-$date', '$season', $competition, $squad)";
		$result = mysql_query($sql);
		if($result) {
			print "This fixture has now been saved";
		} else {
			print "ERROR\n";
		}
	}
?>
<form action=addfixture.php method=post>
<input type=hidden name=update value=yes>
<select name=opponents>
<?
	$sql = "SELECT id,name,country FROM opponent ORDER BY country, name";
	$result = mysql_query($sql);
	while(list($id, $name) = mysql_fetch_row($result)) {
		print "<option value=$id>$name";
    	}
?>
</select><br>
<select name=venue>
<option>home
<option>away
<option>neutral
</select><br>
<select name=year>
<?
	print_options(1985, 2015);
?>
</select><select name=mon>
<?	print_options(1, 12);	?>
</select><select name=date>
<?	print_options(1,31);	?>
</select><br>
<select name=squad>
<br>
<?
	$sql = "SELECT id,name FROM squad";
	$result = mysql_query($sql);
	while(list($id, $name) = mysql_fetch_row($result)) {
		print "<option value=$id>$name";
    	}
	
?>
</select><br>
<? competition_menu(-1, $connection); ?><br>
Season: <? print "<input type=text name=season value=$thisseason>" ?> <br>
<input type=submit>
</form>

<p>
<a href=admingames.php> Back to main games page </a>
<br>
<a href=index.html>Back to main admin page </a>
</body>
</html>
