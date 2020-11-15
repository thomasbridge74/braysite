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
	$action = $_REQUEST['action'];
	$season = $_REQUEST['season'];
	$squad = $_REQUEST['squad'];

	if(!$action) { $action = "list"; }

	if($action == "list") {
		if(!$season) { $season = $thisseason; }
		if(!$squad) { $squad = 1; }
		$sql = "SELECT game.id,opponent.name,game.date FROM game,opponent WHERE game.opponents = opponent.id AND game.season = '$season' AND game.squad = $squad ORDER BY game.date";
		# print "<pre>$sql</pre>";
		$result = mysql_query($sql);
		while(list($id, $name, $date) = mysql_fetch_array($result)){
			if($name == "") { $name = "No opponent defined" ;}
			print "$date <a href=$PHP_SELF?squad=$squad&action=update&game=$id>$name</a><br>";
		}
	}
	if($action == "commitupdate") {

		$opponent = $_REQUEST['opponent'];
		$venue = $_REQUEST['venue'];
		$year = $_REQUEST['year'];
		$mon = $_REQUEST['mon'];
		$day = $_REQUEST['day'];
		$season = $_REQUEST['season'];
		$competition = $_REQUEST['competition'];
		$squad = $_REQUEST['squad'];
		$brayscore = $_REQUEST['brayscore'];
		$oppscore = $_REQUEST['oppscore'];
		$game = $_REQUEST['game'];
		
		if($brayscore != "") {
			$sql = "UPDATE game SET opponents = $opponent, venue = '$venue', bray_score = $brayscore, opp_score = $oppscore, date = '$year-$mon-$day', competition = $competition WHERE id = $game";
		} else {
			$sql = "UPDATE game SET opponents = $opponent, venue = '$venue', date = '$year-$mon-$day', competition = $competition WHERE id = $game";
		}

		if(mysql_query($sql)) {
			print "<h1>Update succeeded</h1>";
		} else {
			print "<h1>Update failed</h1>";
			print "<h2>".mysql_error()."</h2>";
			print "<pre>$sql</pre>";
			phpinfo(INFO_VARIABLES);
		}
		$action = "update";
	}
	if($action == "update") {
		$game = $_REQUEST['game'];
		$sql = "SELECT * FROM game WHERE id = $game";
		$result = mysql_query($sql);
		list($id, $opponentid, $venue, $brayscore, $oppscore, $date, $competitionid) = mysql_fetch_array($result);
		print "<form action=admingames.php method=post>";
		print "<input type=hidden name=action value=commitupdate>";
		print "<input type=hidden name=game value=$id>";
		print "<input type=hidden name=squad value=$squad>";
		print "<table>";
		print "<tr><td>Opponent</td><td>"; opponent_menu($opponentid, $connection); print "</td></tr>";
		print "<tr><td>Venue</td><td>"; venue_menu($venue); print "</td></tr>";
		print "<tr><td>Bray Score</td><td><input length=2 value=\"$brayscore\" name=brayscore type=text></td></tr>";
		print "<tr><td>Opponent Score</td><td><input length=2 value=\"$oppscore\" name=oppscore type=text></td></tr>";
		print "<tr><td>Date</td><td>"; print_date_menu($date, ""); print "</td></tr>";
		print "<tr><td>Competition</td><td>"; competition_menu($competitionid, $connection); print "</td></tr>";
		print "</table><input type=submit value=\"Update details for this game\">";
		print "</form>";
		print "<form action=admingames.php method=post>";
		print "<input type=hidden name=game value=$game>";
		print "<input type=hidden name=action value=delete>";
		# print "<h1>Reports</h1>";
		print "<ul>";
		# $sql = "SELECT columnist.name,game.columnist FROM game,columnist WHERE game.id = $game AND columnist.id = game.columnist";
		# $sql = "select columnist.name,report.columnist FROM report,columnist WHERE report.game = $game AND columnist.id = report.columnist";
		$sql = "select columnist FROM report WHERE game = $game"; 
		# print "<pre>$sql</pre>";

		$result = mysql_query($sql);
		while(list($col) = mysql_fetch_array($result)) {
			print "<li><a href=editreport.php?game=$game&columnist=$col>Report $col</a>\n";
		}
		print "</ul>";
		print "<a href=addreport.php?game=$game>Add a report for this match</a><p>";
		print "<input type=submit value=\"Delete this game\"><p>";
		print "</form>";
		print "Options below do not affect this game<p>";
	}
	if($action == "delete") {
		$game = $_REQUEST['game'];
		$sql = "DELETE FROM game WHERE id = $game";
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

<ul>
<li><a href=addreport.php>Add a report</a> NOTE: this allows you to select any game for the report.
<li><? result_season_menu ($squad, $connection, $PHP_SELF);?> 
<li><a href="admingames.php?action=list&squad=<?print $squad?>">This season</a>
<li><? squad_select_list($connection, "admingames.php?action=list") ?>
<li><a href=addfixture.php>Add a new fixture</a>
</ul>

<form action=addopponent.php method=post>
<input type=text name=opponent>
<br>
<select name=area>
<option>ireland
<option>abroad
</select>
<br>
<input type=submit value="Add this opponent">
</form>

<form action=addcompetition.php method=post>
<input type=text name=competition>
<br>
<input type=submit value="Add this competition">
</form>
<p>
<a href=admingames.php> Back to main games page </a>
<br>
<a href=index.html>Back to main admin page </a>
</body>
</html>
