let display = ""; // calculator display
let currentValue = 0; // first value
let tempValue = 0; // second value
let operatorType = ""; // operator
let clearMe = false; // set to clear display on button press
let editing = false; // entering the second number

function getNumber(buttonValue) {
  // press button
  if (clearMe) {
    // clear everything
    clearDisplay();
    clearMe = false;
  }
  if (editing) {
    // clear display for second number
    display = "";
    editing = false;
  }
  // concat the numbers
  display += buttonValue;
  // set display
  document.getElementById("displayText").innerText = display;
  // store current value
  currentValue = display;
}

function calculateType(type) {
  // pressed an operatpr
  tempValue = currentValue; // store first number
  currentValue = 0; // reset
  editing = true; // set to enter second value
  operatorType = type; // set operatorType
}

function finalResult() {
  // equals button
  switch (
    operatorType // do caulations based on operatorType
  ) {
    case "add":
      tempValue = parseInt(tempValue) + parseInt(currentValue);
      break;
    case "subtract":
      tempValue = parseInt(tempValue) - parseInt(currentValue);
      break;
    case "multiply":
      tempValue = parseInt(tempValue) * parseInt(currentValue);
      break;
    case "divide":
      tempValue = parseInt(tempValue) / parseInt(currentValue);
      break;
  }
  operatorType = ""; // clear operatorType
  document.getElementById("displayText").innerText = tempValue; // set display
  currentValue = 0; // reset
  tempValue = 0; // reset
  clearMe = true; // clear value on press
  editing = false; // clear editing
}

function clearText() {
  // clear the display
  display = "";
  document.getElementById("displayText").innerText = "0";
}