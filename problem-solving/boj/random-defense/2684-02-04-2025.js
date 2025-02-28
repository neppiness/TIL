const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isNo = true;
rl.on('line', line => {
  if (isNo) {
    isNo = false;
  } else {
    solve(line);
  }
}).on('close', () => {
  process.exit();
});


function solve(line) {
  let memo = {};
  memo.TTT = 0;
  memo.TTH = 0;
  memo.THT = 0;
  memo.THH = 0;
  memo.HTT = 0;
  memo.HTH = 0;
  memo.HHT = 0;
  memo.HHH = 0;
  for (let i = 0; i < 38; i++) {
    const ss = line.substring(i, i + 3);
    memo[ss]++;
  }
  console.log(memo.TTT, memo.TTH, memo.THT, memo.THH, memo.HTT, memo.HTH, memo.HHT, memo.HHH);
}
