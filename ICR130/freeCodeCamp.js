/* 
Verify this certification at 
https://freecodecamp.org/certification/Chang_Li/javascript-algorithms-and-data-structures
*/

/*
Test - 1 Palindrome Checker
https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/javascript-algorithms-and-data-structures-projects/palindrome-checker

function palindrome(str) {
    let cleanedInput = str.toLowerCase().replace(/[^a-z0-9]/g, '');
    let reverseInput = cleanedInput.split('').reverse().join('');
    return cleanedInput === reverseInput;
  }
palindrome("eye");
*/


/*
Test - 2 Roman Numeral Converter

https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/javascript-algorithms-and-data-structures-projects/roman-numeral-converter


function convertToRoman(num) {
    let roman = '';
    let romanNumeral = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I'];
    let arabicNumeral = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    
    for (let i = 0; i < arabicNumeral.length; i++) {
      while (num >= arabicNumeral[i]) {
        roman += romanNumeral[i];
        num -= arabicNumeral[i];
      }
    }
    
    return roman;
  }
*/


/*
Test - 3 Caesars Cipher
// https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/javascript-algorithms-and-data-structures-projects/caesars-cipher

function rot13(str) {
  let decoded = '';
  
  for (let i = 0; i < str.length; i++) {
    let charCode = str.charCodeAt(i);
    if (charCode < 65 || charCode > 90) {
      decoded += str[i];
      continue;
    }
    decoded += String.fromCharCode((charCode - 65 + 13) % 26 + 65);
  }
  
  return decoded;
}
rot13("SERR PBQR PNZC");


Test - 4 Telephone Number Validator
https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/javascript-algorithms-and-data-structures-projects/telephone-number-validator

function telephoneCheck(str) {
    let regex = /^(1\s?)?(\(\d{3}\)|\d{3})[\s\-]?\d{3}[\s\-]?\d{4}$/;

return regex.test(str);
}

telephoneCheck("555-555-5555");
*/

/*
Test - 5 Cash Register
https://www.freecodecamp.org/learn/javascript-algorithms-and-data-structures/javascript-algorithms-and-data-structures-projects/cash-register

function checkCashRegister(price, cash, cid) {
    let changeDue = cash - price;
    let change = [];
    let totalCid = cid.reduce((acc, curr) => acc + curr[1], 0);
    const currencyUnits = [    ["PENNY", 0.01],
      ["NICKEL", 0.05],
      ["DIME", 0.1],
      ["QUARTER", 0.25],
      ["ONE", 1],
      ["FIVE", 5],
      ["TEN", 10],
      ["TWENTY", 20],
      ["ONE HUNDRED", 100]
    ];
  
    if (totalCid < changeDue) {
      return { status: "INSUFFICIENT_FUNDS", change: [] };
    }
  
    if (totalCid === changeDue) {
      return { status: "CLOSED", change: cid };
    }
  
    for (let i = currencyUnits.length - 1; i >= 0; i--) {
      let unitName = currencyUnits[i][0];
      let unitValue = currencyUnits[i][1];
      let unitCount = 0;
  
      while (changeDue >= unitValue && cid[i][1] >= unitValue) {
        changeDue -= unitValue;
        changeDue = Math.round(changeDue * 100) / 100;
        cid[i][1] -= unitValue;
        unitCount++;
      }
  
      if (unitCount > 0) {
        change.push([unitName, unitValue * unitCount]);
      }
    }
  
    if (changeDue > 0) {
      return { status: "INSUFFICIENT_FUNDS", change: [] };
    }
  
    return { status: "OPEN", change: change };
  }
  
  
  checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]);

  */