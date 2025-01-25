const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

let y = false;
rl.on('line', line => {
  for (let i = 1; i < line.length; i++) {
    const s1 = line.substring(0, i)
    const s2 = line.substring(i)
    let mul1 = parseInt(s1[0])
    for (let j = 1; j < s1.length; j++) {
      mul1 *= parseInt(s1[j])
    }
    let mul2 = parseInt(s2[0])
    for (let j = 1; j < s2.length; j++) {
      mul2 *= parseInt(s2[j])
    }
    if (mul1 === mul2) y = true
  }
}).on('close', () => {
  if (y) console.log('YES')
  else console.log('NO')
  process.exit()
})
