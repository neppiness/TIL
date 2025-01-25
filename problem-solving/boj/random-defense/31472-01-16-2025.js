const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  let a = parseInt(line)
  a *= 2
  console.log(Math.sqrt(a) * 4)
}).on('close', () => {
  process.exit()
})
