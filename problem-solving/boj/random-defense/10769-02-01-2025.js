const readline = require('readline')
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', line => {
  let pos = line.match(/:-\)/g);
  let neg = line.match(/:-\(/g);
  if (pos === null) {
    pos = [];
  }
  if (neg === null) {
    neg = [];
  }
  pos = pos.length;
  neg = neg.length;
  if (pos === 0 && neg === 0) {
    console.log('none')
  } else if (pos === neg) {
    console.log('unsure')
  } else if (pos > neg) {
    console.log('happy')
  } else {
    console.log('sad')
  }
}).on('close', () => {
  process.exit()
})
