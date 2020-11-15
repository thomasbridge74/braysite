<? 
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

	$todays_date = todays_date();
	$game = $_REQUEST['game'];
	$sql = "SELECT body FROM report WHERE game = $game"; 
	$result = mysql_query($sql);
	if(mysql_num_rows($result) == 0) {
		print "No Reports for this game";
	} else {
		while(list($body) = mysql_fetch_array($result)) {
			$body = stripslashes($body);
			print preg_replace("/[\n\r]+/", "<p>", $body);
		}
	}
		
	

?>
