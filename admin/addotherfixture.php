<html>
<head>
<title>
Add Fixture
</title>
</head>

<body>
<h1> WARNING: 2002 fixtures only please </h1>
<?
	include("functions.inc");
	function print_options($start, $end) {
		for($i = $start; $i <= $end; $i++){
			print "<option>$i";
		}
	}
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

   	if($update) {
		$sql = "INSERT INTO othergame (opponents, venue, date, season, competition, team) VALUES ($opponents, '$venue', '$year-$mon-$date', '$season', $competition, '$team')";
		print "$sql";
		mysql_query($sql);
	}
?>
<form action=addotherfixture.php method=post>
<input type=hidden name=update value=yes>
<select name=team>
<option>under18
<option>under21
<option>Ireland
</select><br>

<select name=opponents>
<?
	$sql = "SELECT id,name FROM opponent ORDER BY name";
	$result = mysql_query($sql);
	while(list($id, $name) = mysql_fetch_row($result)) {
		print "<option value=$id>$name";
    	}
?>
</select><br>
<select name=venue>
<option>home
<option>away
</select><br>
<select name=year>
<?
	print_options(2002, 2003);
?>
</select><select name=mon>
<?	print_options(1, 12);	?>
</select><select name=date>
<?	print_options(1,31);	?>
</select>

<br>
<? competition_menu(-1, $connection); ?><br>
Season: <input type=text name=season value=2002><br>
<input type=submit>
</form>
</body>
</html>
