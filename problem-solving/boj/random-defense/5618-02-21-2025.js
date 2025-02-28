const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let isCount = true;
rl.on('line', line => {
  if (isCount) {
    isCount = false;
  } else {
    const a = line.split(' ').map(a => parseInt(a));
    const gcd = getGcd(a);
    printCD(gcd);
  }
}).on('close', () => {
  process.exit();
});

function calcGcd(a, b) {
  return a == 0 ? b : calcGcd(b % a, a);
}

function getGcd(a) {
  const gcd1 = calcGcd(a[0], a[1]);
  if (a.length == 2) {
    return gcd1;
  }
  const gcd2 = calcGcd(a[0], a[2]);
  return calcGcd(gcd1, gcd2);
}

function printCD(gcd) {
  let ansSet = new Set();
  for (let i = 1; i <= Math.sqrt(gcd); i++) {
    if (gcd % i === 0) {
      ansSet.add(i);
    }
    let j = Math.floor(gcd / i);
    if (gcd % j === 0) {
      ansSet.add(j);
    }
  }
  let ans = [...ansSet];
  ans.sort((a, b) => a - b);
  for (let i of ans) {
    console.log(i);
  }
}
