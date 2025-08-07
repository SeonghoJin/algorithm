// @ts-check
const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : './Javascript/dev/stdin.txt')
  .toString()
  .trim()
  .split(/\s+/)
  .map(Number);

const main = () => {
  let n = input[0];

  const f = (start, end, current) => {
    if (current === 1) {
      return 1;
    }

    let answer = 0;

    if ((start + 1) % 3 !== 2 && current % 3 !== 2) {
      answer += f(start + 1, end, current - 1);
    }

    if (end % 3 !== 2 && current % 3 !== 2) {
      answer += f(start, end - 1, current - 1);
    }

    if ((start + 1) % 3 === 2 && current % 3 == 2) {
      answer += f(start + 1, end, current - 1);
    }

    if (end % 3 === 2 && current % 3 === 2) {
      answer += f(start, end - 1, current - 1);
    }

    return answer;
  };

  console.log(f(0, n * 3, n * 3));
};

main();
