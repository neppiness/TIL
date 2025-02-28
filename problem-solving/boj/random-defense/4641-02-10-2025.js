const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  if (line === '-1') {
    rl.emit('close');
  }
  const a = line.split(' ').map(a => parseInt(a));
  const memo = {};
  for (let i = 0; i < a.length - 1; i++) {
    memo[a[i] * 2] = 1;
  }
  let count = 0;
  for (let i = 0; i < a.length - 1; i++) {
    if (memo[a[i]]) {
      count += memo[a[i]];
    }
  }
  console.log(count);
}).on('close', () => {
  process.exit();
});
