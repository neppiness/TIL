'use strict';

const readline = require('readline');

const rl = readline.createInterface(
    process.stdin,
    process.stdout
);

let b = [];
let n;

rl.once('line', (line) => {
  n = Number(line);

  b = Array(n);
  b.forEach((arr) => {
    arr.push(Array(n));
  });
})

rl.on('line', (line) => {
  
}).on('close', () => {
  main();
  process.exit();
})

function main() {
}