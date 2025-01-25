const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  ouput: process.stdout
})


rl.on('line', line => {
  const a = line.split(' ').map(a => parseInt(a))
  for (let i = 0; i < a.length; i++) {
    if (a[i] === 9) {
      console.log('F')
      process.exit()
    } else {
      continue
    }
  }
  console.log('S')
  process.exit()
})
