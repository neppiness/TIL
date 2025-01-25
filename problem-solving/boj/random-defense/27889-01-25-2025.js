const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

const table = {
  NLCS: 'North London Collegiate School',
  BHA: 'Branksome Hall Asia',
  KIS: 'Korea International School',
  SJA: 'St. Johnsbury Academy',
}

rl.on('line', line => {
  console.log(table[line])
}).on('close', () => {
  process.exit()
})
