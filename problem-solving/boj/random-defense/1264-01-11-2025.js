const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let ans = '';
rl.on('line', line => {
  if (line === '#') return
  let cnt = 0
  for (let i = 0; i < line.length; i++) {
    const a = line.charAt(i).toLowerCase()
    if (a === 'a' || a === 'e' || a === 'i' || a === 'o' || a === 'u')
      cnt++
  }
  ans += cnt + '\n'
}).on('close', () => {
  console.log(ans)
  process.exit()
})
