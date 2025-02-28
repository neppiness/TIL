const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isNo = true;
let ans = 0;
rl.on('line', line => {
  if (isNo) {
    isNo = false;
  } else {
    const n = parseInt(line.substring(2));
    if (n <= 90) ans++;
  }
}).on('close', () => {
  console.log(ans);
  process.exit();
});
