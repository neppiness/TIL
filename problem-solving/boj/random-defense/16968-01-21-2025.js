const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  let ans
  if (line[0] === 'd') {
    ans = 10
  } else {
    ans = 26
  }

  for (let i = 1; i < line.length; i++) {
    let mul
    if (line[i] === 'c') {
      mul = 26
    } else {
      mul = 10
    }
    if (line[i] === line[i - 1]) mul--
    ans *= mul
  }
  console.log(ans)
}).on('close', () => {
  process.exit()
})
