const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let ans = '';
rl.on('line', line => {
  for (let i = 0; i < line.length; i++) {
    let a = parseInt(line.charAt(i), 8);
    a = a.toString(2);
    if (i == 0) {
      ans += a;
    } else {
      ans += ('0'.repeat(3 - a.length) + a);
    }
  }
}).on('close', () => {
  console.log(ans);
  process.exit();
});
