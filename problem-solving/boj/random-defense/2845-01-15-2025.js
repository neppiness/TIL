const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

const lines = []
rl.on('line', line => {
  lines.push(line)
}).on('close', () => {
  solve()
  process.exit()
})

let ans = ''
solve = () => {
  let [no, ar] = lines[0].split(' ')
    .map(e => parseInt(e))

  lines[1].split(' ')
    .map(e => parseInt(e))
    .forEach(aa => ans += (aa - no * ar) + ' ')

  console.log(ans)
}
