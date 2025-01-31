const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  const [h, m] = line.split(' ').map(a => parseInt(a))
  const min = h * 60 + m
  console.log(min - 540)
}).on('close', () => {
  process.exit()
})
