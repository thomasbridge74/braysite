<table border="0" cellpadding="3" cellspacing="0">
<tr><td colspan=4><p><a href=http://www.braywanderers.com/showarticle.php?id=706>Full Fixture Lists (Premier, League Cup, FAI Cup &c)</a></td></tr>
<tr>
<td>
<p>
<?
        include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
	$squad = $_REQUEST['squad'];
        mysql_select_db($dbname, $connection);

        $todays_date = todays_date();
	if(!$squad) $squad = 1 ;
        $sql = "SELECT opponent.name, game.venue, game.date, game.bray_score, game.opp_score, competition.title
FROM game,opponent, competition
WHERE opponent.id = game.opponents
AND competition.id = game.competition
AND game.squad = $squad
AND game.date >= '$todays_date'
ORDER BY game.  date ";
        $result = mysql_query($sql);
        while ( list($name, $venue, $date, $bray, $opp, $comp) = mysql_fetch_array($result) ) {
                print("<tr><td><p>$date</td><td><p><i>$comp</i></td><td><p>$venue</td><td><p>$name</td></tr>"); 
        }
?>
</td></tr>
<tr><td colspan=4>
<?
squad_select_list($connection, $_SERVER['PHP_SELF'])
?></td></tr>
</table>
