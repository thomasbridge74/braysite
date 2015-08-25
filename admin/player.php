<html>
<head>
<title>
Player Management
</title>
</head>

<body>

<?
	include("functions.inc");
	$connection = mysql_connect($dbserver, $dbuser, $dbpass);
	mysql_select_db($dbname, $connection);


	if($_REQUEST['update']) {
		// UPDATE
		$story = addslashes($_REQUEST['story']);
		$firstname = addslashes($_REQUEST['firstname']);
		$surname = addslashes($_REQUEST['surname']);
		$id = $_REQUEST['id'];
		$current = $_REQUEST['current'];
		
		if($id == 0) {
			$sql = "INSERT INTO player (id, firstname, surname, current, story) VALUES (0, '$firstname', '$surname', '$current', '$story')";
		} else {
			$sql = "UPDATE player SET firstname = '$firstname', surname = '$surname', current = '$current', story = '$story' WHERE id = $id";
		}
		mysql_query($sql);
//		phpinfo(INFO_VARIABLES);
//		print "<pre>\n$sql\n</pre>";
		if($id == 0) { $id = mysql_insert_id(); }
		update_squad($id);
	} elseif($_REQUEST['new']) {
		player_form(0, "", "", "", "");
	} elseif($_REQUEST['edit']) {
		$sql = "SELECT firstname,surname,current,story FROM player WHERE id = ".$_REQUEST['edit'];
		$result = mysql_query($sql);
		list($firstname, $surname, $current, $story) = mysql_fetch_array($result);
		$firstname = stripslashes($firstname);
		$surname = stripslashes($surname);
		$story = stripslashes($story);
		player_form($_REQUEST['edit'], $firstname, $surname, $current, $story);
	} 
		
	$sql = "SELECT id,firstname,surname,current FROM player ORDER BY current, surname, firstname";
	$result = mysql_query($sql);
	$lastcur = "";
	while(list($id, $firstname, $surname, $current) = mysql_fetch_array($result)) {
		if($current != $lastcur) {
			print "<h2>Current status: $current</h2>";
		}
		$lastcur = $current;
		$firstname = stripslashes($firstname);
		$surname = stripslashes($surname);
		print "<a href=".$_SERVER['PHP_SELF']."?edit=$id> $firstname $surname </a><br>";
	}

	print "<p><a href=".$_SERVER['PHP_SELF']."?new=yes>Add a new player</a><p>";

	function player_form($id, $firstname, $surname, $current, $story) {
		print "USE SINGLE QUOTES IN THE FORM<br>\n";
		print " _SERVER['PHP_SELF'] is ". $_SERVER['PHP_SELF'];
		print "<form action=".$_SERVER['PHP_SELF']." method=post>\n";
		print "<input type=hidden value=$id name=id><input type=hidden name=update value=yes>";
		print "<table><tr><td>Firstname</td><td><input type=text name=firstname value=\"$firstname\"></td></tr><tr><td>Surname</td><td><input type=text name=surname value=\"$surname\"></td></tr>";
		print "<tr><td>At club?</td><td><select name=current>";
		if($current == "no") {
			print "<option selected>no<option>yes\n";
		} else {
			print "<option selected>yes<option>no\n";
		}
		print "</select></td></tr>";
		print "<tr><td>Biography</td><td><textarea rows=10 cols=50 name=story>$story</textarea></td></tr>";
		print "</table>";
		squadlist($id);
		print "<input type=submit value=\"Update this entry\"></form>\n</body></html>";
	}

	function squadlist($player) {
		$sql = "SELECT id,name FROM squad";
		$psql = "SELECT squad FROM squadentry WHERE player = $player";
		$squadresult = mysql_query($sql);
		$playerresult = mysql_query($psql);
		while(list($squad) = mysql_fetch_array($playerresult)) {
			$SQUADIN[$squad] = 1;
		}
		while(list($id, $name) = mysql_fetch_array($squadresult)) {
			if($SQUADIN[$id]) {
				print "<input type=checkbox name=squad$id value=yes checked> $name <br>";
			} else {
				print "<input type=checkbox name=squad$id value=yes> $name <br>";
			}
		}
	}

	function update_squad($player) {
		// phpinfo(32);
		$squadsql = "SELECT id FROM squad";
		$squadresult = mysql_query($squadsql);
		mysql_query("DELETE FROM squadentry WHERE player = $player");
		while(list($squad)  = mysql_fetch_array($squadresult)) {
			$entry = "squad$squad";
			if($_POST[$entry]) {
				$newsql = "INSERT INTO squadentry VALUES ($player, $squad)";
				if($updateresult = mysql_query($newsql)) {
					print "Added to squad $squad<br>";
				} else {
					print "Error adding to squad $squad<br>";
				}
			}
		}
	}
?>
		
