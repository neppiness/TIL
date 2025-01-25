const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let inputs = []
let ans = ''
rl.on('line', line => {
  inputs.push(line)
}).on('close', () => {
  solve()
  process.exit()
})

solve = () => {
  let i = 0
  let t = parseInt(inputs[i++])
  while (t--) {
    let memo = {}
    let n = parseInt(inputs[i++])
    let max = 0
    while (n--) {
      [school, drink] = inputs[i++].split(' ')
      if (!memo[school]) {
        memo[school] = 0
      }
      memo[school] += parseInt(drink)
      max = Math.max(memo[school], max)
    }
    for (let key in memo) {
      if (max !== memo[key]) continue
      ans += (key + '\n');
      break
    }
  }
  console.log(ans)
}

