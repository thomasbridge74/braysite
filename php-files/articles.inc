<table border="0" cellpadding="3" cellspacing="0">
<tr><td valign="top" width="481"  height="300" align="left" colspan="3"><p>
<?	
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

?>

<a name=field>
<h1>The Field of Dreams</h1></a>
<p>	Jack O'Neill's musings on the current state of Soccer, from the Seagull Scene, Bray Wanderers' Matchday Programme

<? 
	show_title(1, $connection);
?>


<a name=story>
<h1>The Story so Far</h1></a>
<p>	Mick Duffy on the statistics of the Seagulls' games against other League and Cup opposition, and player statistics and achievements

<?
	show_title(7, $connection);
?>
<a name=keane>
<h1>Keane's Scene</h1></a>
<img src="/image/people/ckeane.jpg" alt="Colm Keane" border=0 align=right><p>	Pen portraits of Bray Wanderers Players and other Club Personalities, by the award-winning broadcaster and writer, <b>Colm Keane</b>, author of <i>A Cut Above The Rest</i> (Townhouse, 1999), as well as <i>Tales of the Wanderers</i> (Colado, 1998) and <i>More Tales of the Wanderers</i> (Colado, 2000), together with other volumes based on his work for RTÉ Radio.




<?
	show_title(2, $connection);
?>
<a name=scealta>
<h1>Scéalta Sacair</h1></a>
<p>	Smaointe Fánacha ar chúrsaí sacair Thall is Abhus, le Mícheál Ó hUanacháin

<?
	show_title(9, $connection);
?>

<a name=people>
<h1>People in Play</h1></a>
<p>	How the media view Bray Wanderers and and other aspects of Irish Soccer


<?
	show_title(8, $connection);
?>
<a name=fans>
<h1>Fans' Focus</h1></a>
  <p>     Pen Portraits of new players, personalities and people behind the pitch

<?
	show_title(10, $connection);
?>

<a name=bigger>
<h1>The Bigger Picture</h1></a>
<p>	Reports and Articles from other media on Irish Soccer, and other topics of common interest

<?
	show_title(11, $connection);
?>
<p>
<a name=past>
<h1>Glimpses of the Past</h1></a>
<p>	Historical articles and features on Bray Wanderers, their predecessors and their Town

<?
	show_title(12, $connection);
?>

<A name=salvo><h1>Brian's Salvoes</h1></a>
<p>
<?
	show_title(14, $connection);
?>

<A name=cahill><h1>Paul Cahill Looking Back</h1></a>
<p>
<?
	show_title(13, $connection);
?>
<p align=center>
[<a href=#field>Field of Dreams</a>]
[<a href=#story>The Story so Far</a>]
[<a href=#keane>Keane Scene</a>]
[<a href=#scealta>Scéalta Sacair</a>]
[<a href=#people>People in Play</a>]
[<a href=#fans>Fans Focus</a>]		
[<a href=#bigger>The Bigger Picture</a>]
[<a href=#past>Glimpses of the Past</a>]
[<a href=#cahill>Looking Back</a>]

</p>

<p>Soccer clubs and programme editors are welcome to use original material from this site.  Please credit the Bray Wanderers website www.braywanderers.ie for anything you use.  Please don't use anything first published other than by Bray Wanderers without permission.
  </td></tr>
 
</table>
