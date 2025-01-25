const readline = require('readline')

const rl = readline.createInterface(
  input = process.stdin,
  output = process.stdout
);

let ans = BigInt(0)
rl.on('line', line => {
  const a = parseInt(line)
  for (let i = 1; i < a; i++) {
    ans += BigInt(i * a + i)
  }
}).on('close', () => {
  console.log(ans.toString())
  process.exit
})
