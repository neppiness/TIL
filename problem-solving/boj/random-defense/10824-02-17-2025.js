const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const [a, b, c, d] = line.split(' ');
  let AB = a + b;
  let CD = c + d;
  console.log(parseInt(AB) + parseInt(CD));
}).on('close', () => {
  process.exit();
});
