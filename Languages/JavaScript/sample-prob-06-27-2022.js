'use strict';

const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

let inputData = [];
let count = 0;
let result = 0;

rl.on('line', (input) => {
  inputData.push(input);
  const noOfTestCases = Number(inputData[0]);

  if(count >= noOfTestCases*2) {
    rl.close();
  }
  ++count;
})

rl.on('close', () => {
  let intSplitedInputData = [];
  inputData.forEach((oneInputLine) => {
    let splitedOneInputLine = oneInputLine.split(' ');
    let intTypeOneInputLine = splitedOneInputLine.map((aLine) => parseInt(aLine));
    intSplitedInputData.push(intTypeOneInputLine);
  })

  const inputInIntArr = intSplitedInputData;
  const noOfTestCases = inputInIntArr[0][0];

  for (let count = 0; count < noOfTestCases; count++) {
    let index = 2*count + 1;
    let kidsNumber = inputInIntArr[index][1];

    let candiesNumber = inputInIntArr[index + 1].reduce(function (previousValue, currentValue) {
      return previousValue + currentValue
      }, 0
    )

    result = candiesNumber % kidsNumber;
    console.log(`Case #${count+1}: ${result}`)    
  }
})