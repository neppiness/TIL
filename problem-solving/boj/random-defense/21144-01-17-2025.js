const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let ip = []

rl.on('line', line => {
  ip.push(line)
}).on('close', () => {
  solve()
  process.exit()
})

solve = () => {
  const n = parseInt(ip[0])
  const str = ip[1]

  let pos = 0
  for (let i = 1; i < n; i++) {
    const no = i.toString()
    const ss = str.substring(pos, pos + no.length)
    pos += no.length
    if (no === ss) continue
    console.log(no)
    return
  }
  console.log(n)
}
