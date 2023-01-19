/* NOTE FOR CODE SAMPLE */

/*
Find the Longest Word in a String
Return the length of the longest word in the provided sentence.
*/

-- javascript auto-format --
/*
https://beautifier.io/
https://www.freeformatter.com/javascript-beautifier.html#before-output
 */

function findLongestWordLength(str) {
    return Math.max(...str.split(" ").map(word => word.length));
   }
   
   findLongestWordLength("The quick brown fox jumped over the lazy dog");

/*Check if a string (first argument, str) ends with the given target string (second argument, target). */
function confirmEnding(str, target) {
    return str.slice(str.length - target.length) === target;    
}

confirmEnding("Bastian", "n");



function frankenSplice(arr1, arr2, n) {
    let newArr=[];
    for(let i=0;i<n;i++){
      newArr[i]=arr2[i];
    }
    for(let j=n;j<(arr1.length+n);j++){
      newArr.push(arr1[j-n]);          
    }
    for(let k=n+arr1.length; k<(arr1.length+arr2.length); k++){
      newArr.push(arr1[k-arr1.length-n]);
    return newArr;
  }
  }
frankenSplice([1, 2, 3], [4, 5, 6], 1);