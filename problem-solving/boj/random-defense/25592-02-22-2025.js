const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const a = parseInt(line);
  let cur = -1;
  while (1) {
    cur++;
    let puang = calcSum(cur * 2 + 1);
    let friend = calcSum(cur * 2);

    if (puang < a) {
      continue;
    }
    if (friend <= a) {
      console.log(puang - a);
    } else {
      console.log(0);
    }
    rl.emit('close');
  }
}).on('close', () => {
  process.exit();
});

function calcSum(a) {
  return a * (a + 1) / 2;
}
