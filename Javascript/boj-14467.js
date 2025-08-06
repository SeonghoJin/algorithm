// @ts-check

const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : './Javascript/dev/stdin.txt')
  .toString()
  .trim()
  .split(/\s+/)
  .map(Number);

const main = () => {
  const m = new Map();
  let answer = 0;
  for (let i = 0; i < input[0]; i++) {
    const [cow, position] = [input[1 + 2 * i], input[1 + 2 * i + 1]];

    const currentCowPosition = m.get(cow);
    m.set(cow, position);

    if (currentCowPosition !== undefined && position !== currentCowPosition) {
      answer++;
    }
    m.set(cow, position);
  }
  console.log(answer);
};

main();
