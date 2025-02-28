const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  let [a, b, c, d, e] = line.split(' ').map(no => parseInt(no));
  while (!is_aligned(a, b, c, d, e)) {
    let tmp;
    if (a > b) {
      tmp = a;
      a = b;
      b = tmp;
      console.log(a, b, c, d, e);
    }
    if (b > c) {
      tmp = b;
      b = c;
      c = tmp;
      console.log(a, b, c, d, e);
    }
    if (c > d) {
      tmp = c;
      c = d;
      d = tmp;
      console.log(a, b, c, d, e);
    }
    if (d > e) {
      tmp = d;
      d = e;
      e = tmp;
      console.log(a, b, c, d, e);
    }
  }

}).on('close', () => {
  process.exit();
});

function is_aligned(a, b, c, d, e) {
  return (a === 1 && b === 2 && c === 3 && d === 4 && e === 5);
}

