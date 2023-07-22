'use strict';

const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let ans = '';
let cnt = 0;
rl.on('line', line => {
  if (cnt++ == 0) return;
  let [a, b] = line.split(' ');
  [a, b] = [parseInt(a), parseInt(b)];
  ans += (a + b) + '\n';
}).on('close', () => {
  console.log(ans);
  process.exit();
});