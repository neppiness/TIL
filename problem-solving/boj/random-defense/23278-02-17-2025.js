const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let lines = [];
rl.on('line', line => {
  lines.push(line);
}).on('close', () => {
  const [n, l, h] = lines[0].split(' ').map(a => parseInt(a));
  const nos = lines[1].split(' ').map(a => parseInt(a)).sort();
  let sum = 0;
  for (let i = l; i < n - h; i++) {
    sum += nos[i];
  }
  console.log(sum / (n - h - l));
  process.exit();
});
