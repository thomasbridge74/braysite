<html>
<head>
<title>Add News Article</title>
</head>

<body bgcolor=white text=black>
<?
        include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);
	$action = $_REQUEST['action'];
	$headline = $_REQUEST['headline'];
	$details = $_REQUEST['details'];
	$category = $_REQUEST['category'];
	$dateyear = $_REQUEST['dateyear'];
	$datemon = $_REQUEST['datemon'];
	$dateday = $_REQUEST['dateday'];
	$expireyear = $_REQUEST['expireyear'];
	$expiremon = $_REQUEST['expiremon'];
	$expireday = $_REQUEST['expireday'];
	
	print "action is $action";

	if($action == 'insert') {
		# Add news item dammit :)
		$insert = $_REQUEST['insert'];
		$sql = "INSERT INTO news VALUES (0, '".todays_date()."', '".addslashes($headline).
			"', '".addslashes($details)."', '$category', '$expireyear-$expiremon-$expireday')";
		mysql_query($sql);
	}
	if($action == 'update') {
		$edit = $_REQUEST['edit'];
		$sql = "UPDATE news SET headline = '".addslashes($headline)."', details = '"
			.addslashes($details)."', date = '$dateyear-$datemon-$dateday', category = '$category', expire='$expireyear-$expiremon-$expireday'  WHERE id = $edit";
		mysql_query($sql);
		print "Update applied<p>";
	}
	if($action == 'edit') {
		$edit = $_REQUEST['edit'];
		$sql = "SELECT date,headline,details,expire FROM news WHERE id = $edit";
		$result = mysql_query($sql);
		list($date, $headline, $details, $expire) = mysql_fetch_row($result);
	}


    ?>

<form action=addnews.php method=post>
<? if($edit) { ?>
	<input type=hidden name=action value=update>
	<input type=hidden name=edit value="<? echo $edit; ?>">
<? } else { ?>
	<input type=hidden name=action value=insert>
	<input type=hidden name=insert value=yes>
<? } ?>
Date added: 
<? if ($edit || $update) { print_date_menu($date, "date"); } else { print_date_menu(todays_date(), "date"); } ?>
<select name=category><option value=club>News From Bray Wanderers AFC<option value=supporters>Bray Wanderers Supporters Club News
<option value=other>What's New in Irish Soccer
<option value=worldcup>Bray Wanderers Team News
</select><Br>
Headline: <input type=text name=headline value="<? echo stripslashes($headline); ?>"><br>
Details:<br>
<textarea rows=8 cols=60 name=details>
<? echo stripslashes($details); ?>
</textarea><br>
Expire date:
<? if ($edit || $update) { print_date_menu($expire, "expire"); } else { print_date_menu(todays_date(), "expire"); } ?>
<p>
<input type=submit value="Add this story">
</form>
<form action=delnews.php method=post>
<input type=submit value="Delete this story">
<input type=hidden name=id value=<? echo $edit; ?>>
</form>


<a href=news-admin.php>Back to News Admin</a>
