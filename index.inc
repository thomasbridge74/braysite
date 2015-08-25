<H2>Bray Wanderers Supporters Club web site</h2>
<br>
<body>
<script language="JavaScript1.2">

/***********************************************
* Flexi Slideshow- © Dynamic Drive (www.dynamicdrive.com)
* This notice must stay intact for use
* Visit http://www.dynamicdrive.com/ for full source code
***********************************************/

var variableslide=new Array()

//variableslide[x]=["path to image", "OPTIONAL link for image", "OPTIONAL text description (supports HTML tags)"]

variableslide[0]=['BW 1974.jpg', '', '']
variableslide[1]=['Green Army.jpg', '', '']
variableslide[2]=['BW 1943-44.jpg', '', '']
variableslide[3]=['BW 1955-56.jpg', '', '']
variableslide[4]=['Supporters Club Flag.jpg', '', '']
variableslide[5]=['BW 1976.jpg', '', '']
variableslide[6]=['Bray Wanderers 1950-51.jpg', '', '']
variableslide[7]=['BW 1999 FAI Cup Winners.jpg', '', '']

//configure the below 3 variables to set the dimension/background color of the slideshow

var slidewidth='170px' //set to width of LARGEST image in your slideshow
var slideheight='150px' //set to height of LARGEST iamge in your slideshow, plus any text description
var slidebgcolor='#F3F3F3'

//configure the below variable to determine the delay between image rotations (in miliseconds)
var slidedelay=9000

////Do not edit pass this line////////////////

var ie=document.all
var dom=document.getElementById

for (i=0;i<variableslide.length;i++){
var cacheimage=new Image()
cacheimage.src=variableslide[i][0]
}

var currentslide=0

function rotateimages(){
contentcontainer='<center>'
if (variableslide[currentslide][1]!="")
contentcontainer+='<a href="'+variableslide[currentslide][1]+'">'
contentcontainer+='<img src="'+variableslide[currentslide][0]+'" border="0" vspace="3">'
if (variableslide[currentslide][1]!="")
contentcontainer+='</a>'
contentcontainer+='</center>'
if (variableslide[currentslide][2]!="")
contentcontainer+=variableslide[currentslide][2]

if (document.layers){
crossrotateobj.document.write(contentcontainer)
crossrotateobj.document.close()
}
else if (ie||dom)
crossrotateobj.innerHTML=contentcontainer
if (currentslide==variableslide.length-1) currentslide=0
else currentslide++
setTimeout("rotateimages()",slidedelay)
}

if (ie||dom)
document.write('<div id="slidedom" style="width:'+slidewidth+';height:'+slideheight+'; background-color:'+slidebgcolor+'"></div>')

function start_slider(){
crossrotateobj=dom? document.getElementById("slidedom") : ie? document.all.slidedom : document.slidensmain.document.slidenssub
if (document.layers)
document.slidensmain.visibility="show"
rotateimages()
}

if (ie||dom)
start_slider()
else if (document.layers)
window.onload=start_slider

</script>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<ilayer id="slidensmain" width=&{slidewidth}; height=&{slideheight}; bgColor=&{slidebgcolor}; visibility=hide><layer id="slidenssub" width=&{slidewidth}; left=0 top=0></layer></ilayer>
<br>

</body>
<br>

<script type="text/javascript">

/***********************************************
* Fading Scroller- © Dynamic Drive DHTML code library (www.dynamicdrive.com)
* This notice MUST stay intact for legal use
* Visit Dynamic Drive at http://www.dynamicdrive.com/ for full source code
***********************************************/

var delay = 6000; //set delay between message change (in miliseconds)
var maxsteps=30; // number of steps to take to change from start color to endcolor
var stepdelay=40; // time in miliseconds of a single step
//**Note: maxsteps*stepdelay will be total time in miliseconds of fading effect
var startcolor= new Array(255,255,255); // start color (red, green, blue)
var endcolor=new Array(0,0,0); // end color (red, green, blue)

var fcontent=new Array();
begintag='<div style="font: normal 14px Arial; padding: 5px;">'; //set opening tag, such as font declarations
fcontent[0]="<b>What\'s new?</b>";
fcontent[1]="Fixture: SSE Airtricity Premier Division,<br>Senior Team away to Longford, Saturday 29 August, KO 7.30pm";
fcontent[2]="Bray Wanderers drawn at home to Killester United in FAI Cup Quarter Final";
fcontent[3]=" New Club badges now available – see Shop for more details";
fcontent[4]=" Next away bus trip is to Longford on 29 August – see News for more details";

closetag='</div>';

var fwidth='400px'; //set scroller width
var fheight='70px'; //set scroller height

var fadelinks=1;  //should links inside scroller content also fade like text? 0 for no, 1 for yes.

///No need to edit below this line/////////////////


var ie4=document.all&&!document.getElementById;
var DOM2=document.getElementById;
var faderdelay=0;
var index=0;


/*Rafael Raposo edited function*/
//function to change content
function changecontent(){
  if (index>=fcontent.length)
    index=0
  if (DOM2){
    document.getElementById("fscroller").style.color="rgb("+startcolor[0]+", "+startcolor[1]+", "+startcolor[2]+")"
    document.getElementById("fscroller").innerHTML=begintag+fcontent[index]+closetag
    if (fadelinks)
      linkcolorchange(1);
    colorfade(1, 15);
  }
  else if (ie4)
    document.all.fscroller.innerHTML=begintag+fcontent[index]+closetag;
  index++
}

// colorfade() partially by Marcio Galli for Netscape Communications.  ////////////
// Modified by Dynamicdrive.com

function linkcolorchange(step){
  var obj=document.getElementById("fscroller").getElementsByTagName("A");
  if (obj.length>0){
    for (i=0;i<obj.length;i++)
      obj[i].style.color=getstepcolor(step);
  }
}

/*Rafael Raposo edited function*/
var fadecounter;
function colorfade(step) {
  if(step<=maxsteps) {	
    document.getElementById("fscroller").style.color=getstepcolor(step);
    if (fadelinks)
      linkcolorchange(step);
    step++;
    fadecounter=setTimeout("colorfade("+step+")",stepdelay);
  }else{
    clearTimeout(fadecounter);
    document.getElementById("fscroller").style.color="rgb("+endcolor[0]+", "+endcolor[1]+", "+endcolor[2]+")";
    setTimeout("changecontent()", delay);
	
  }   
}

/*Rafael Raposo's new function*/
function getstepcolor(step) {
  var diff
  var newcolor=new Array(3);
  for(var i=0;i<3;i++) {
    diff = (startcolor[i]-endcolor[i]);
    if(diff > 0) {
      newcolor[i] = startcolor[i]-(Math.round((diff/maxsteps))*step);
    } else {
      newcolor[i] = startcolor[i]+(Math.round((Math.abs(diff)/maxsteps))*step);
    }
  }
  return ("rgb(" + newcolor[0] + ", " + newcolor[1] + ", " + newcolor[2] + ")");
}

if (ie4||DOM2)
  document.write('<div id="fscroller" style="border:1px solid black;width:'+fwidth+';height:'+fheight+'"></div>');

if (window.addEventListener)
window.addEventListener("load", changecontent, false)
else if (window.attachEvent)
window.attachEvent("onload", changecontent)
else if (document.getElementById)
window.onload=changecontent

</script>

<br>
<? 
	include("functions.inc");
	$connection = mysql_connect($dbserver, $dbuser, $dbpass);
	mysql_select_db($dbname, $connection);
	$gameid = print_latest_score(1, $connection) ;?>

<a 
href="http://www.braywanderers.com/reports.php?game=<? 
print $gameid ?>"><p>Match
Report</a> 
<br>
<rem: unlock next fixture when f06 are loaded>
<?	 ?> <p> <?
	print_next_fixture($connection, 1); ?><br>
<br>

<?
	print_latest_news($connection); 
?>  <a href=news.php>More news</a><p>

<br>
<img src="/image/u19s/ssea-ball-sm.jpg" height=85 align=left><p>
<a href="/showarticle.php?id=731"><b>Youth Teams</b></a>

<a href="http://www.twitter.com/braysuppclub"><img src="/image/logos/twitter-sm.jpg" align=right></a> <a href="http://www.facebook.com/pages/Bray-Wanderers-Supporters-Club/140927215968668"><img src="/image/logos/facebook-sm.jpg" align=right></a><br><br><br><br><br>
<a href="https://clubapplive.com/soccer/index.html?clubid=263"><img src="/image/logos/clubapp-sm.jpg" align=right></a><p>
<iframe  id="Fundraising-Draws"src="https://www.myclubfinances.com/fundraising-draws.asp?t_id=1&v_id=1478" HEIGHT="155" WIDTH="150" SCROLLING="no" FRAMEBORDER="" style="border:0px solid #FFFFFF;margin:0px;"></iframe>
<br>
</b><br><br><a href="/showarticle.php?id=109">Lotto Draw Details</a><br>
<p><a href="/showarticle.php?id=610"><img src="/image/club/shop-icon.jpg"></a><br>
<table><tr><td colspan="3" valign="top" 
align="center"></td></tr></table><table><tr><td>	</td>	<td width="350">
	<p><b>FAI Cup Winners 1990, 1999<br><br>	
		First Division Champions 1985/86, 
1995/96, 1999/2000<br>Shield 
Winners 1995/96<br><br>Enda McGuill Cup Winners 2005</b>			<p 
align=center><a href="/showarticle.php?id=79"><h3>Roll 
of Honour</h3></a></p>			</td>		
        <td><img src="/image/misc/d1-99.jpg" 
height=123></td></tr></table>

<!--<table width=481>		<tr><td colspan="3"></td></tr>	
		<tr><td colspan="2">		

		<a href="showarticle.php?
id=110"><h1>Devo</h1></a>			</td>	
		<td><a href="showarticle.php?
id=110"></a></td></tr>			<tr><td 
colspan="3"></td></tr></table>-->

<h4> <a 
href="http://www.braywanderers.com/showarticle.php?
id=91">Do you want to know where "The Field of Dreams" is?</a></h4>

<!--<table width=479><tr><td>--> 

<h4> <a 
href="http://www.braywanderers.com/showarticle.php?
id=658">Club History</a></h4>

<!--<table width=479><tr><td>--> 
<iframe  id="newsletter"src="http://www.myclubfinances.com/subscribe-to-newsletter.asp?t_id=2&amp;v_id=216" height="180" width="450" scrolling="no" frameborder="" style="border:0px solid #e1e1e1;margin:1px;"></iframe>

<p>This site is dedicated to all Seagulls' Fans, and is not the official Club site.<br>
<br>
<a href="http://www.bwfc.ie">Click here to visit the official web site of Bray Wanderers Football Club</a>
<br>
<p>Come back soon and see what's new!
</p>