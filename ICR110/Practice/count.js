
//Print current Page function
function print_current_page()
{
window.print();
}

//The bloody Bulb function

function nextBulb() 
{ 
  if (document.getElementById("myImage").src.match("pic_bulboff"))
  { 
    document.getElementById("myImage").src = "pic_bulbon.gif";
  } 
  else if (document.getElementById("myImage").src.match("pic_bulbon"))
  {
    document.getElementById("myImage").src = "pic_bulboff.gif";
  }
}
  

//Click counter
let countclick=0;
function clicked(clicked) {
if (clicked==="clicked") {
  countclick++;
  document.getElementById("clickedoutput").innerText = "Times clicked: " + countclick;
  }
  else if (countclick===0) {
    document.getElementById("clickedoutput").innerText="No clicks";
  }
}