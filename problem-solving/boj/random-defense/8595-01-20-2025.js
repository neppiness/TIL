const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

const lines = []
rl.on('line', line => {
  lines.push(line)
}).on('close', () => {
  solve()
  process.exit()
})

solve = () => {
  const str = lines[1]
  const ans = str.split(/[a-zA-Z]+/)
    .filter(a => a.length > 0)
    .map(a => parseInt(a))
    .reduce((acc, cur) => acc + cur, 0)
  console.log(ans)
}
