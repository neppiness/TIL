const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const val = [500, 100, 50, 10, 5, 1];

rl.on('line', line => {
  let n = 1000 - parseInt(line);
  let ans = 0;
  for (let i = 0; i < 6; i++) {
    const div = Math.floor(n / val[i]);
    ans += div;
    n -= div * val[i];
  }
  console.log(ans);
}).on('close', () => {
  process.exit();
});
