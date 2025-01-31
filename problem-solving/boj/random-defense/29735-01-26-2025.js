const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

const a = []
rl.on('line', line => {
  a.push(line)
}).on('close', () => {
  solve()
  process.exit()
})

function parseTime(hm) {
  const [h, m] = hm.split(':')
  return parseInt(h) * 60 + parseInt(m)
}

function toTime(min) {
  let h = Math.floor(min / 60)
  if (h < 10) h = '0' + h
  let m = min % 60
  if (m < 10) m = '0' + m
  return h + ':' + m
}

function calcDays(perDay, n) {
  return Math.floor(n / perDay)
}

function solve() {
  const [st, en] = a[0].split(' ').map(tm => parseTime(tm))
  const d = en - st - 1

  let [n, t] = a[1].split(' ').map(x => parseInt(x))
  n++

  const perDay = Math.floor(d / t)
  const days = calcDays(perDay, n)
  const remain = (n - perDay * days)
  const ans = toTime(remain * t + st)

  console.log(days)
  console.log(ans)
}
