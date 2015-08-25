<table cellspacing=3>
<?

	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);
	$season = $_REQUEST['season'];
	$squad = $_REQUEST['squad'];

	$todays_date = todays_date();
	if(!$squad) $squad = 1;
	if(!$season) { $season = $thisseason; }
	$sql = "SELECT opponent.name, game.venue, game.date, game.bray_score, game.opp_score, game.id, competition.title FROM game,opponent,competition WHERE opponent.id = game.opponents AND game.squad = $squad AND game.competition = competition.id AND game.date < '$todays_date' AND game.season = '$season' ORDER BY game.date";
	$result = mysql_query($sql);
	while ( list($name, $venue, $date, $bray, $opp, $id, $comp) = mysql_fetch_array($result) ) {
		print("<tr><td>$date</td><td><i>$comp</i></td><td>$venue</td><td>$name</td><td align=center>$bray</td><td align=center>$opp</td><td><a href=reports.php?game=$id>Reports</a></tr>"); 
	}
?>
<tr><td colspan=7><? result_season_menu($squad,$connection,$_SERVER['PHP_SELF']) ?></td></tr>
<tr><td colspan=7><? squad_select_list($connection, $_SERVER['PHP_SELF']) ?></td></tr>
</table>
