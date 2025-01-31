const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const memo = {};
const lines = [];
rl.on('line', line => {
  lines.push(line);
}).on('close', () => {
  solve();
  process.exit();
})

function count(string) {
  for (let i = 0; i < string.length; i++) {
    const char = string[i];
    if (memo[char] === undefined) {
      memo[char] = 1;
    } else {
      memo[char]++;
    }
  }
}

function determine() {
  const tCount = memo.t + memo.T;
  const sCount = memo.s + memo.S;
  if (sCount >= tCount) {
    return 'French';
  }
  return 'English';
}

function setMemo() {
  if (memo.t === undefined) {
    memo.t = 0;
  }
  if (memo.T === undefined) {
    memo.T = 0;
  }
  if (memo.s === undefined) {
    memo.s = 0;
  }
  if (memo.S === undefined) {
    memo.S = 0;
  }
}

function solve() {
  const n = parseInt(lines[0]);
  for (let i = 1; i <= n; i++)
    count(lines[i]);
  setMemo();
  console.log(determine());
}
