

//Print current Page function
function print_current_page()
{
window.print();
}

//The bloody Bulb function

function myFunction() {
  alert("print is not vailable");
}

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
  }

  
  //Colors change on a button



const colors = ['red', 'green', 'blue', 'purple'];

function changeBtnColor() {
  let index = 0;

  btn = document.getElementById('colorfun');
  btn.style.backgroundColor = colors[index];
  btn.style.color = 'black';
  index = index >= colors.length - 1 ? 0 : index + 1;

}
//btn.addEventListener("click", function onClick() {
  
//});