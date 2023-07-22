'use strict';

const path = require("path");
let input = require("fs").readFileSync(path.resolve(__dirname, "./test.txt"), "utf-8");
// let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let splitInput = input.split("\n");

let inputArray = [];
splitInput.forEach(
    input => inputArray.push(input.replace(/\r/g, "")
));

let [n, m] = inputArray[0].split(' ');


console.log(inputArray);
process.exit();
let a = [], b = [];
for (let i = 1; i <= n; i++) {
  let row = splitInput[i];
  a.push(row.split(' '));
}
for (let i = n + 1; i <= 2*n; i++) {
  let row = splitInput[i];
  b.push(row.split(' '));
}

for (let i = 0; i < n; i++) {
  let row = [];
  for (let j = 0; j < m; j++)
    row.push(a[i][j] + b[i][j]);
  console.log(row.join(' '));
}
