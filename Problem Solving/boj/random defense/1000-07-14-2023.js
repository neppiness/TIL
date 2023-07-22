const readline = require('readline');
const rl = readline.createInterface(process.stdin, process.stdout);

rl.on('line', line => {
  let a = line.split(' ');
  console.log(Number(a[0]) + Number(a[1]));
}).on('close', () => process.exit());