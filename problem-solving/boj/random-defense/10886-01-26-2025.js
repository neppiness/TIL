const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

const a = []
rl.on('line', line => {
  a.push(line)
}).on('close', () => {
  solve()
  process.exit()
})

function solve() {
  const n = parseInt(a[0])
  let c = 0, nc = 0
  for (let i = 1; i <= n; i++) {
    if (a[i] === '0') {
      nc++
    } else {
      c++
    }
  }
  if (c > nc) {
    console.log('Junhee is cute!')
  } else {
    console.log('Junhee is not cute!')
  }
}
