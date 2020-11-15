	<table border="0" cellpadding="3" cellspacing="0">
<tr><td valign="top" width="481" height="300" align="left" colspan="3"><p>

<p>

<?
        include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

	if(!$squad) { $squad = 1;}
	$squadname = squad_name($squad, $connection);
	print "<h2>The current members of the $squadname squad:</h2><p>";
       
        $sql = "SELECT player.firstname, player.surname, player.story FROM player,squadentry WHERE player.current = 'yes' AND player.id = squadentry.player AND squadentry.squad = $squad ORDER BY player.surname,player.firstname ";
        $result = mysql_query($sql);

	while(list($firstname, $surname, $story) = mysql_fetch_array($result)) { 
        	echo "<h4>", stripslashes($firstname), " ",  stripslashes($surname), "</h4><p>"; 
                echo stripslashes($story); 
	}  // end while loop 
	squad_select_list($connection, $_SERVER['PHP_SELF']);
?>
<p>
<i>Pen pics by <b>Michael Duffy</b>.</i>
<p>
<i>Soccer clubs and programme editors are welcome to use original material from this site.  Please credit the website braywanderers.com for anything you use.</i>
</td></tr> 
</table>
