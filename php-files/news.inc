<table border="0" cellpadding="0" cellspacing="0"> <tr><td valign="top" width="481" height="300" align="left" colspan="3"><p>
<?
 	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

?>  <h2>Supporters Club News</h2> <p> Meetings, Special Events, Souvenir News, Travel arrangements, Club activities <p> <table> <? 	show_news("supporters", $connection); ?> </table>  
 <h2> News From Bray Wanderers AFC</h2> 
<p> <table> <?  	show_news("club", $connection); ?> </table> 
<h2> Bray Wanderers Latest Team News</h2> <p> Team News, Injuries, Suspensions ahead of Next Game. <table> <? 	show_news("worldcup", $connection); ?> </table><h2>What's New in Irish Soccer</h2> <p> FAI and National Team News, Former Seagulls' activities, Issues and Controversies, Irish Clubs abroad <p> <table> <? 	show_news("other", $connection); ?> </table> 
</td></tr> </table>
<p> All News text is &copy Bray Wanderers Supporters Club. Editorial enquiries to the Editor, <a href=mailto:bwsc@eircom.net>BWSC</a> 
