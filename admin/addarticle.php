<html>
<head>
<title> Bray Wanderers Results </title>
</head>

<body bgcolor="white" text="#00C000">
<basefont face="arial">

<? 
	function quote($arg1) {
		return ("'".preg_replace("'", "\\'", $arg1)."'");
	}
	$action = $_REQUEST['action'];
	if(! $columnist) { $columnist = -1; }
	include("functions.inc");
        $connection = mysql_connect($dbserver, $dbuser, $dbpass);
        mysql_select_db($dbname, $connection);

#	phpinfo(INFO_VARIABLES);

	if($action == 'addentry') {
		$columnist = $_REQUEST['columnist'];
		$title = $_REQUEST['title'];
		$article = $_REQUEST['article'];

		$sql = "INSERT INTO article VALUES (0, $columnist, '"
		.addslashes($title)."', '0000-00-00', '".addslashes($article)."')";
		if(mysql_query($sql)) {
			print "<h1>Update succeeded</h1>";
			print "<a href=listarticles.php?columnistid=$columnist>This columnist</a><p>";
		} else {
			print "<h1>Update failed</h1>";
			print "<h2>".mysql_error()."</h2>";
			print "<pre>$sql</pre>";
		}
	}
	if($action == 'edit') {
		$edit = $_REQUEST['edit'];
		$sql = "SELECT id, columnist, title, body FROM article WHERE id = $edit";
		$result = mysql_query($sql);
		list($id, $columnist, $title, $body) = mysql_fetch_array($result);
	}
	if($action == 'update') {
		$columnist = $_REQUEST['columnist'];
		$title = $_REQUEST['title'];
		$article = $_REQUEST['article'];
		$articleid  = $_REQUEST['articleid'];
		$edit = $articleid;
		$id = $edit;
		$body = $article;

		$article = addslashes($article);
		$title = addslashes($title);

		$sql = "UPDATE article SET columnist = $columnist,
			body = '$article', title = '$title' WHERE id = $articleid";

		#if(mysql_query(mysql_real_escape_string($sql))) {
		if(mysql_query($sql)) {
			print "<h1>Update succeeded</h1>";
		} else {
			print "<h1>Update failed</h1>";
			print "<h2>".mysql_error()."</h2>";
			print "<pre>$sql</pre>";
		}
	}
?>

<form action="addarticle.php" method="post">
<? 	if($edit) { ?>
	<input type=hidden name=action value=update>
	<input type=hidden name=articleid value=<? print $id; ?>>
<?	} else { ?>
	<input type=hidden name=action value=addentry>
<?	}	?>
<select name=columnist>
<?
	$sql = "SELECT id,name FROM columnist";
	$result = mysql_query($sql);
	while(list($id,$name) = mysql_fetch_array($result)) {
		if($id == $columnist) {
			print("<option value=$id selected>$name");
		} else {
			print("<option value=$id>$name");
		}
	}
?>
</select><p>
Title: <input type=text name=title value="<? if($edit) { print stripslashes($title); } ?>"><p>
Body:<br>
<textarea name="article" rows=40 cols=70>
<? if($edit) { print stripslashes($body); } ?>
</textarea><br>
<input type=submit>
</form>
</table><p>

<hr>

<form action=deletearticle.php>
<input type=hidden name=edit value=<? echo $edit?>>
<input type=submit value="Delete This">

</form>
</body>
</html>
