const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let wUniv = [];
let kUniv = [];
let cnt = 0;
rl.on('line', line => {
  if (cnt++ < 10) {
    wUniv.push(parseInt(line));
  } else {
    kUniv.push(parseInt(line));
  }
}).on('close', () => {
  solve();
  process.exit();
});

function solve() {
  wUniv.sort((a, b) => a - b);
  kUniv.sort((a, b) => a - b);

  let ans1 = wUniv.at(7) + wUniv.at(8) + wUniv.at(9);
  let ans2 = kUniv.at(7) + kUniv.at(8) + kUniv.at(9);
  console.log(ans1, ans2);
}
