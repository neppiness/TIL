const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

const LEFT = 'left', RIGHT = 'right'

let prvDir

function getDir(digits) {
  const no = parseInt(digits)
  const tenth = Math.floor(no / 10)
  const oneth = no % 10

  if (tenth === 0 && oneth === 0) return prvDir
  prvDir = (tenth + oneth) % 2 === 0 ? RIGHT : LEFT
  return prvDir
}

rl.on('line', line => {
  if (line === '99999') rl.emit('close')
  
  let dir = line.substring(0, 2)
  let step = line.substring(2)
  console.log(getDir(dir), parseInt(step))

}).on('close', () => {
  process.exit()
})

