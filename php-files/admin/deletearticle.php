<html>
<head><title>Delete</title>
</head>
<body>

<?
	$edit = $_REQUEST['edit'];
	
	if($_REQUEST['confirmed']) {
		// Delete the damn article
		
		        include("functions.inc");
       		 $connection = mysql_connect($dbserver, $dbuser, $dbpass);
       		 mysql_select_db($dbname, $connection);

		$sql = "DELETE FROM article WHERE id = $edit";
		if(mysql_query($sql)) {
			print "Deleted successfully";
		} else {
			print "Bugger!  Something went wrong and the programmer can't remember the name of the error string variable";
		}
	} else { ?>
		<form action=deletearticle.php method=post>
		Are you drop dead certain you want to do this?  <p>Deleting the wrong article
		could lead to us setting Roddy Collins on you!
		<input type=hidden name=edit value=<?echo $edit?>>
		<input type=hidden name=confirmed value=yes>
		<br>
		<input type=submit value="I'm not scared of Roddy">
		</form> <?
	}
	?>

<p>
<a href=listarticles.php>Articles</a><br>
<a href=index.html>Home </a>
	
</body>
</html>

