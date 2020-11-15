<html>
<head>
<title>Add a player</title>
</head>

<body>
<?
        include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

	if($insert) {
		$firstname = addslashes($firstname);
		$surname = addslashes($surname);
		$story = addslashes($story);
		$sql = "INSERT INTO player (firstname, surname, story) VALUES ('$firstname', '$surname', '$story')";
		print $sql;
		mysql_query($sql);
	}
?>

<form action=addplayer.php3 method=post>
<input type=hidden value=yes name=insert>
Firstname: <input type=text name=firstname><br>

Surname: <input type=text name=surname><br>

Description:<br>
<textarea rows=5 cols=60 name=story>
</textarea><br>
<input type=submit value="Add player">
</form>

