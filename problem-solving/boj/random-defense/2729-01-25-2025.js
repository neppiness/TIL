import readline from 'readline'
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let a = []
rl.on('line', line => {
  a.push(line)
}).on('close', () => {
  solve()
  process.exit()
})

function solve() {
  const n = parseInt(a[0])
  for (let i = 1; i <= n; i++) {
    const ans = a[i].split(' ')
    ans[0]
  }
}

