const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const ABC = 'abcdefghijklmnopqrstuvwxyz';

let is_no = true;
let ans = '';
rl.on('line', line => {
  if (is_no) {
    is_no = false;
  } else {
    const [a, b] = line.split(' ');
    if (solve(a, b)) {
      ans += `${a} & ${b} are anagrams.\n`;
    } else {
      ans += `${a} & ${b} are NOT anagrams.\n`;
    }
  }
}).on('close', () => {
  console.log(ans);
  process.exit();
})


function solve(a, b) {
  let aMemo = {};
  let bMemo = {};

  for (let i = 0; i < ABC.length; i++) {
    aMemo[ABC[i]] = 0;
    bMemo[ABC[i]] = 0;
  }

  for (let i = 0; i < a.length; i++) aMemo[a[i]]++;
  for (let i = 0; i < b.length; i++) bMemo[b[i]]++;

  for (let i = 0; i < ABC.length; i++) {
    if (aMemo[ABC[i]] !== bMemo[ABC[i]]) {
      return false;
    }
  }
  return true;
}
