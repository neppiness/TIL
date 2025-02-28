const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let lines = [];
rl.on('line', line => {
  lines.push(line);
}).on('close', () => {
  solve();
  process.exit();
});

let comb = '';
function solve() {
  for (let i = 0; i < 8; i++)
    comb += lines[0].charAt(i) + lines[1].charAt(i);

  while (comb.length > 2) {
    let temp = '';
    for (let i = 0; i < comb.length - 1; i++) {
      temp += (parseInt(comb.charAt(i)) + parseInt(comb.charAt(i + 1))) % 10;
    }
    comb = temp;
  }
  console.log(comb);
}
