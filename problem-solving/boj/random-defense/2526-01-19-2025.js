const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let memo = {};
rl.on('line', line => {
  const [n, p] = line.split(' ').map(a => parseInt(a))
  memo[n] = 1
  let cur = n
  while (1) {
    cur = cur * n % p
    if (memo[cur] === undefined) {
      memo[cur] = 1
      continue
    }
    memo[cur]++
    if (memo[cur] !== 3) continue
    let ans = 0;
    for (let key in memo) {
      if (memo[key] >= 2) ans++
    }
    console.log(ans)
    break
  }
}).on('close', () => {
  process.exit()
})
