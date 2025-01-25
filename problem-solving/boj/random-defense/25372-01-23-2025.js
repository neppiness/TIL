const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let a = []
rl.on('line', line => {
  a.push(line)
}).on('close', () => {
  solve();
  process.exit()
})

solve = () => {
  const n = parseInt(a[0])
  for (let i = 1; i <= n; i++) {
    if (a[i].length >= 6 && a[i].length <= 9) {
      console.log('yes')
    } else {
      console.log('no')
    }
  }
}
