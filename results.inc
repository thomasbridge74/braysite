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
<a href="full-results.php">Full season's results</a>
<p>

<!-- BEGIN of Soccerway widget HTML fragment  -->
<!-- Personal code for this widget: tZ6gztj530EgEtnsn -->
<iframe src="http://widgets.soccerway.com/widget/free/classic/competition/34/1192#d=350x300&f=table,table_colmp,table_colmw,table_colmd,table_colml,table_colgf,table_colga,table_colgd&cbackground=FFFFFF&ctext=000000&ctitle=F85F00&cshadow=E8E8E8&cbutton=FFFFFF&cbuttontext=000000&chighlight=000000&tbody_family=Tahoma,sans-serif&tbody_size=9&tbody_weight=normal&tbody_style=normal&tbody_decoration=none&tbody_transform=none&ttitle_family=Impact,sans-serif&ttitle_size=13&ttitle_weight=normal&ttitle_style=normal&ttitle_decoration=none&ttitle_transform=none&ttab_family=Tahoma,sans-serif&ttab_size=9&ttab_weight=normal&ttab_style=normal&ttab_decoration=none&ttab_transform=none" width="350" height="300" scrolling="no" frameborder="0" marginwidth="0" marginheight="0"></iframe>
<!-- END of Soccerway widget HTML fragment -->


<p>
<a href="http://www.braywanderers.com/showarticle.php?id=167">Bray Wanderers Results/Team line-ups
Archive</a>
<p>
<a href="http://www.braywanderers.com/showarticle.php?id=620">Players' Records Archive</a>
<p>
<a href="http://www.braywanderers.com/showarticle.php?id=618">Bray Wanderers Season by Season Stats Archive</a>
<p>
<a href="http://www.braywanderers.com/showarticle.php?id=619">Bray Wanderers Supporters Club Player of the Year & Month Archive</a>
