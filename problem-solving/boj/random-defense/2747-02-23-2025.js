const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let a = new Array(47);

rl.on('line', line => {
  a[0] = 0;
  a[1] = 1;
  const n = parseInt(line);
  for (let i = 2; i <= n; i++)
    a[i] = a[i - 1] + a[i - 2];
  console.log(a[n]);
}).on('close', () => {
  process.exit();
});
