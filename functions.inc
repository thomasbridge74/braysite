<?
#
# Variable definitions
#

include("settings.inc");

function todays_date() {
	return date("Y-m-d");
}

function print_date_menu ($date, $variable) {
	list($year,$mon,$day)= preg_split("/-/", $date);
	print "<select name=${variable}day>\n";
	for($i = 1; $i <= 31; $i++) {
		if($i == $day) { 
			print "<option selected>";
		} else {
			print "<option>";
		}
		print "$i\n";
	}
	print "</select>";
	print "<select name=${variable}mon>\n";
	for($i = 1; $i <= 12; $i++) {
		if($i == $mon) { 
			print "<option selected>";
		} else {
			print "<option>";
		}
		print "$i\n";
	}
	print "</select>";
	print "<select name=${variable}year>\n";
	#
	# start at 1985 as that is when Bray Wanderers entered the LOI.
	# and yes I know hardcoding this was a bad idea.
	#
	for($i = 1985; $i <= 2025; $i++) {
		if($i == $year) { 
			print "<option selected>";
		} else {
			print "<option>";
		}
		print "$i\n";
	}
	print "</select><br>";
}

function opponent_menu($oppid, $connection) {
	$sql = "select id,name,country FROM opponent ORDER BY country, name";
	$result = mysql_query($sql, $connection);
	print "<select name=opponent>";
	while(list($id, $name, $country) = mysql_fetch_array($result)) {
		if(!$lastcountry) {
			$lastcountry = $country;
		}
		if($country != $lastcountry) {
			print "<option>\n<option>----------<option>\n";
		}
		if($id == $oppid) {
			print "<option value=$id selected>$name";
		} else {
			print "<option value=$id>$name";
		}
	}
	print "</select>";
}

function competition_menu($oppid, $connection) {
	$sql = "SELECT id,title FROM competition";
	$result = mysql_query($sql, $connection);
	print "<select name=competition>";
	while(list($id, $name) = mysql_fetch_array($result)) {
		if($id == $oppid) {
			print "<option value=$id selected>$name";
		} else {
			print "<option value=$id>$name";
		}
	}
	print "</select>";
}

function venue_menu($oppid) {
	$options = array('home', 'away', 'neutral');
	print "<select name=venue>";
	while(list($key, $tmp) = each($options)) {
		if($tmp == $oppid) {
			print "<option selected>$tmp";
		} else {
			print "<option>$tmp";
		}
	}
	print "</select>";
}

function game_menu($game, $connection) {
	$sql = "select game.id,opponent.name,game.date,game.venue from game,opponent where game.opponents = opponent.id and game.date <= '".todays_date()."'";
	$result = mysql_query($sql, $connection);
	print "<select name=game>";
	while(list($id, $name, $date, $venue) = mysql_fetch_array($result)) {
		if($id == $game) {
			print "<option value=$id selected>$name <i>$venue</i> $date </option>\n";
		} else {
			print "<option value=$id>$name <i>$venue</i> $date </option>\n";
		}
	}
	print "</select>";
}

function columnist_menu($oppid, $connection) {
	$sql = "SELECT id,name FROM columnist";
	$result = mysql_query($sql, $connection);
	print "<select name=columnist>";
	while(list($id, $name) = mysql_fetch_array($result)) {
		if($id == $oppid) {
			print "<option value=$id selected>$name";
		} else {
			print "<option value=$id>$name";
		}
	}
	print "</select>";
}


function show_news($category, $connection) {
	$sql = "SELECT id, date, headline FROM news WHERE category = '".$category."' AND expire > '".todays_date()."' ORDER BY date DESC, headline";
	$result = mysql_query($sql, $connection);
	if(!$result) { print mysql_error(); }
	while(list($id, $date, $headline) = mysql_fetch_array($result)) {
		$headline = stripslashes($headline);
		print "<tr><td>$date</td><td><a href=news-article.php?id=$id>$headline</a></td></tr>\n";
	}
} 

function show_title($columnist, $connection) {
	$sql = "SELECT id,title FROM article WHERE columnist = $columnist ORDER BY id DESC LIMIT 2";
	$result = mysql_query($sql, $connection);
	echo "<ul>";
	while(list($id,$title) = mysql_fetch_array($result)) {
		$title = stripslashes($title);
		print "<li><a href=showarticle.php?id=$id>$title</a>";
	}
	print "<li><a href=fulllist.php?columnist=$columnist>More....</a>";
	print "</ul>\n";
}

function delete_news_item($id, $connection) {
	$sql = "DELETE FROM news WHERE id = $id";
	mysql_query($sql);
	print "<h2>News Item $id deleted</h2>";
}

function result_season_menu ($squad, $connection, $action) {
        $sql = "SELECT DISTINCT season FROM game WHERE squad = $squad";
        $result = mysql_query($sql, $connection);
        # print "<form action=full-results.php>\n";
	print "<form action=$action>\n";
        print "<select name=season>\n";
        while(list($season) = mysql_fetch_array($result)) {
                print "<option>$season";
        }
        print "</select>";
	print "<input type=hidden value=$squad name=squad>";
        print "<input type=submit value=\"Change to this season\">";
        print "</form>";
}

function print_latest_score ($squad, $connection) {
	$sql = "SELECT game.id,game.date,opponent.name,game.bray_score,game.opp_score,game.venue FROM opponent,game WHERE opponent.id = game.opponents AND game.bray_score IS NOT NULL AND game.squad = $squad ORDER BY game.date DESC LIMIT 1";
	$result = mysql_query($sql, $connection);
	list($id, $date, $opponent, $brayscore, $oppscore, $venue) = mysql_fetch_array($result);
	if($brayscore > $oppscore) {
		$color = "green";
	} elseif ($brayscore < $oppscore) {
		$color = "black";
	} else {
		$color = "gray";
	}
	print "<h1><font color=$color>";
	if($venue == "away") {
		print "$opponent $oppscore<br>Bray $brayscore";
	} else {
		print "Bray $brayscore<br>$opponent $oppscore";
	}
	print "</font></h1>";
	return $id;
}

function print_next_fixture($connection, $squad) {
	$date = todays_date();
	$sql = "SELECT opponent.name,game.venue,game.date,competition.title FROM opponent,game,competition WHERE opponent.id = game.opponents AND game.competition = competition.id AND game.bray_score IS NULL AND game.date >= '$date' AND game.squad = $squad ORDER BY game.date LIMIT 1";
	$result = mysql_query($sql, $connection);
	
	list($opponent,$venue,$date,$competition) = mysql_fetch_array($result);
	print "Next game: $venue v $opponent, $date, <i>$competition</i>";
}

function print_latest_news($connection) {
	$sql = "SELECT id,headline FROM news ORDER BY date DESC,id DESC LIMIT 1";
	$result = mysql_query($sql, $connection);
	list($id,$headline) = mysql_fetch_array($result);
	$headline = stripslashes($headline);
	print "Latest news: <a href=news-article.php?id=$id>$headline</a>";
}

function squad_select_list($connection, $SELF) {
	print "<form action=$SELF method=post>\n";
	print "<select name=squad>\n";
        $sql = "SELECT id,name FROM squad ORDER BY id";
        $result = mysql_query($sql);
        while(list($id, $name) = mysql_fetch_row($result)) {
                print "<option value=$id>$name";
        }
	print "</select>\n";
	print "<input type=submit value=\"Choose a squad\">";
	print "</form>";
}

function squad_name($id, $connection) {
	$sql = "SELECT name FROM squad WHERE id = $id";
	$result = mysql_query($sql);
	list($name) = mysql_fetch_array($result);
	return $name;
}
?>
