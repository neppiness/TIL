const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let is_no = true;
let ans = '';
rl.on('line', line => {
  if (is_no) {
    is_no = false;
  } else {
    line = line.trim();
    let nos = line.split(' ').map(a => parseInt(a));
    nos = nos.slice(1);
    const evenSum = nos.filter(a => a % 2 === 0).reduce((a, b) => a + b, 0);
    const oddSum = nos.filter(a => a % 2 !== 0).reduce((a, b) => a + b, 0);
    if (evenSum > oddSum) {
      ans += 'EVEN\n';
    } else if (evenSum < oddSum) {
      ans += 'ODD\n';
    } else {
      ans += 'TIE\n';
    }
  }
}).on('close', () => {
  console.log(ans);
  process.exit();
});
