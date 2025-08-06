// @ts-check

const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : './Javascript/dev/stdin.txt')
  .toString()
  .trim()
  .split('\r\n');


const main = () => {
  const [k, d, a] = input[0].split('/').map(Number);
  
  if(k + a < d || d === 0){
    console.log('hasu');
    return;
  }

  console.log('gosu');
  
};

main();
