
<table border="0" cellpadding="3" cellspacing="0"><tr><td valign="top" width="481"><tr><td valign="top" width="481"><p>
<h2 id="fly">Thanks for visiting the Juniors Page</h2>

<script type="text/javascript">

//Flying Letters script- by Matthias (info@freejavascripts.f2s.com)
// Modified by Twey for efficiency and compatibility
//For this script and more, visit Dynamic Drive: http://www.dynamicdrive.com

//Configure message to display. Use "$" for linebreak
//By default, set to just grab the text from element with ID="fly"
message = document.getElementById("fly").innerHTML; // $ = taking a new line
distance = 50; // pixel(s)
speed = 200; // milliseconds

var txt="",
	num=0,
	num4=0,
	flyofle="",
	flyofwi="",
	flyofto="",
	fly=document.getElementById("fly");


function stfly() {
	for(i=0;i != message.length;i++) {
		if(message.charAt(i) != "$")
			txt += "<span style='position:relative;visibility:hidden;' id='n"+i+"'>"+message.charAt(i)+"<\/span>";
		else
			txt += "<br>";
	}
	fly.innerHTML = txt;
	txt = "";
	flyofle = fly.offsetLeft;
	flyofwi = fly.offsetWidth;
	flyofto = fly.offsetTop;
	fly2b();
}

function fly2b() {
	if(num4 != message.length) {
		if(message.charAt(num4) != "$") {
			var then = document.getElementById("n" + num4);
			then.style.left = flyofle - then.offsetLeft + flyofwi / 2;
			then.style.top = flyofto - then.offsetTop + distance;
			fly3(then.id, parseInt(then.style.left), parseInt(then.style.left) / 5, parseInt(then.style.top), parseInt(then.style.top) / 5);
		}
		num4++;
		setTimeout("fly2b()", speed);
	}
}

function fly3(target,lef2,num2,top2,num3) {
	if((Math.floor(top2) != 0 && Math.floor(top2) != -1) || (Math.floor(lef2) != 0 && Math.floor(lef2) != -1)) {
		if(lef2 >= 0)
			lef2 -= num2;
		else
			lef2 += num2 * -1;
		if(Math.floor(lef2) != -1) {
			document.getElementById(target).style.visibility = "visible";
			document.getElementById(target).style.left = Math.floor(lef2);
		} else {
			document.getElementById(target).style.visibility = "visible";
			document.getElementById(target).style.left = Math.floor(lef2 + 1);
		}
		if(lef2 >= 0)
			top2 -= num3
		else
			top2 += num3 * -1;
		if(Math.floor(top2) != -1)
			document.getElementById(target).style.top = Math.floor(top2);
		else
			document.getElementById(target).style.top = Math.floor(top2 + 1);
		setTimeout("fly3('"+target+"',"+lef2+","+num2+","+top2+","+num3+")",50)
	}
}

stfly()

</script>


<img src="/juniors hut.gif"><br><br>


Would you like to lead the team on to the pitch as their mascot? Would you like to meet Rocky the seagull, our mascot?…….. 
If so, why not join Bray Wanderers junior supporters club. It is open to children from 0 right up to the age of 16. 

The main idea behind the Junior Supporters Club is to get children, of all ages, involved in and supporting their local club. They make new friends and receive newsletters through the post. 
<br>
<br>

<img src="/Rocky.jpg">Rocky<br><br>
<img src="/rockyjunior.png">Rocky junior<br><br>
<img src="/emmalally.jpg"><br>Emma Lally<br>
<img src="/karenrooney.jpg"><br>Karen Rooney<br>

<html>


<body>
<div class="marquee" id="mycrawler">

</div>

<script type="text/javascript">
marqueeInit({
uniqueid: 'mycrawler',
style: {
'padding': '5px',
'width': '450px',
'background': 'lightyellow',
'border': '1px solid #CC3300'
},
inc: 8, //speed - pixel increment for each iteration of this marquee's movement
mouse: 'cursor driven', //mouseover behavior (cursor driven)
moveatleast: 4,
neutral: 150,
savedirection: true
});
</script>

</body>
</html>

</table><br>

