
--
-- Table structure for table `article`
--

CREATE TABLE `article` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `columnist` int(11) DEFAULT NULL,
  `title` varchar(70) DEFAULT NULL,
  `published_date` date DEFAULT NULL,
  `body` text,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=735 DEFAULT CHARSET=latin1;

--
-- Table structure for table `columnist`
--

CREATE TABLE `columnist` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` char(40) DEFAULT NULL,
  `author` char(63) DEFAULT NULL,
  `description` char(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=15 DEFAULT CHARSET=latin1;

--
-- Table structure for table `competition`
--

CREATE TABLE `competition` (
  `id` tinyint(4) NOT NULL AUTO_INCREMENT,
  `title` char(60) NOT NULL DEFAULT '',
  PRIMARY KEY (`id`),
  UNIQUE KEY `title_idx` (`title`)
) ENGINE=MyISAM AUTO_INCREMENT=30 DEFAULT CHARSET=latin1;

--
-- Table structure for table `game`
--

CREATE TABLE `game` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `opponents` int(11) NOT NULL DEFAULT '0',
  `venue` enum('home','away','neutral') DEFAULT NULL,
  `bray_score` int(11) DEFAULT NULL,
  `opp_score` int(11) DEFAULT NULL,
  `date` date DEFAULT NULL,
  `competition` tinyint(4) NOT NULL DEFAULT '0',
  `season` char(7) NOT NULL DEFAULT '2001-02',
  `squad` tinyint(4) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=1140 DEFAULT CHARSET=latin1;

--
-- Table structure for table `news`
--

CREATE TABLE `news` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `date` date NOT NULL DEFAULT '0000-00-00',
  `headline` varchar(255) DEFAULT NULL,
  `details` text,
  `category` enum('club','supporters','other','worldcup') NOT NULL DEFAULT 'other',
  `expire` date DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2740 DEFAULT CHARSET=latin1;

--
-- Table structure for table `opponent`
--

CREATE TABLE `opponent` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` char(40) NOT NULL DEFAULT '',
  `country` enum('ireland','abroad') DEFAULT 'ireland',
  PRIMARY KEY (`id`),
  UNIQUE KEY `idx1` (`name`)
) ENGINE=MyISAM AUTO_INCREMENT=150 DEFAULT CHARSET=latin1;

--
-- Table structure for table `othergame`
--

CREATE TABLE `othergame` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `opponents` int(11) NOT NULL DEFAULT '0',
  `venue` enum('home','away','neutral') DEFAULT NULL,
  `bray_score` int(11) DEFAULT NULL,
  `opp_score` int(11) DEFAULT NULL,
  `date` date DEFAULT NULL,
  `competition` tinyint(4) NOT NULL DEFAULT '0',
  `season` char(7) NOT NULL DEFAULT '2001-02',
  `team` enum('under21','under18','Ireland') DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Table structure for table `people`
--

CREATE TABLE `people` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(16) NOT NULL DEFAULT '',
  `password` varchar(16) NOT NULL DEFAULT '',
  `email` varchar(40) DEFAULT NULL,
  `description` text,
  `name` varchar(40) DEFAULT NULL,
  `url` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM AUTO_INCREMENT=3 DEFAULT CHARSET=latin1;

--
-- Table structure for table `player`
--

CREATE TABLE `player` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `firstname` varchar(20) NOT NULL DEFAULT '',
  `surname` varchar(20) NOT NULL DEFAULT '',
  `current` enum('yes','no') NOT NULL DEFAULT 'yes',
  `story` text,
  `picture` blob,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=386 DEFAULT CHARSET=latin1;

--
-- Table structure for table `report`
--

CREATE TABLE `report` (
  `game` int(11) NOT NULL DEFAULT '0',
  `columnist` int(11) NOT NULL DEFAULT '0',
  `body` text,
  PRIMARY KEY (`game`,`columnist`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Table structure for table `squad`
--

CREATE TABLE `squad` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` char(63) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=9 DEFAULT CHARSET=latin1;

--
-- Table structure for table `squadentry`
--

CREATE TABLE `squadentry` (
  `player` int(11) NOT NULL DEFAULT '0',
  `squad` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`player`,`squad`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;
