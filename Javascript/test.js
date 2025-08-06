// @ts-check

const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : './Javascript/dev/stdin.txt')
  .toString()
  .trim()
  .split('\r\n');

const length = Number(input.shift());

const main = () => {
  const arr = input[0]?.split(' ').map(Number);
  console.log(arr);
  let even = 0;
  for (let i = 0; i < length; i += 2) {
    even += arr[i];
  }

  let odd = 0;
  for (let i = 1; i < length; i += 2) {
    odd += arr[i];
  }

  if (length > 3 || even >= odd) {
    console.log(Math.abs(even - odd));
    return;
  }

  console.log(-1);
  return;
};

main();
