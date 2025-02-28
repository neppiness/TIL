const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let count = 0;
rl.on('line', line => {
  if (count++ !== 0) {
    console.log(line);
  }
}).on('close', () => {
  process.exit();
});
