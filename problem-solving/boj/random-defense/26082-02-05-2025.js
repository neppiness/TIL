const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const [a, b, c] = line.split(' ').map(a => parseInt(a));
  console.log(b / a * 3 * c);
}).on('close', () => {
  process.exit();
});
