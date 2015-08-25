<table cellspacing=3>
<?

	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

	$todays_date = todays_date();
	if(!$season) { $season = $thisseason; }
	$sql = "SELECT opponent.name, game.venue, game.date, game.bray_score, game.opp_score, game.id, competition.title FROM game,opponent,competition WHERE opponent.id = game.opponents AND game.competition = competition.id  AND game.bray_score IS NOT NULL ORDER BY game.date DESC LIMIT 5 ";
	$result = mysql_query($sql);
	while ( list($name, $venue, $date, $bray, $opp, $id, $comp) = mysql_fetch_array($result) ) {
		print("<tr><td><p>$date</td><td><p><i>$comp</i></td><td><p>$venue</td><td><p>$name</td><td align=center>$bray</td><td align=center>$opp</td><td><p><a href=reports.php?game=$id>Reports</a></tr>"); 
	}

?>

</table>
<p>
<a href="full-results.php">Full season's results </a>
<p>
<div id="sbWin" style="visibility:hide; position:absolute; z-index: 1;"></div>
<script language="JavaScript" src="http://www.soccerbot.com/fai/tables/irprem02-lt.js"></script> 
<font size=-1>
<script language="JavaScript"> ShowTableLt();</script>
</font>
