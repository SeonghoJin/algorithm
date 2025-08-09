// @ts-check

const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : './Javascript/dev/stdin.txt')
  .toString()
  .trim()
  .split(/\s+/);
const [source, target] = input;
/**
 *
 * @param {string} current
 * @returns
 */
const f = (current) => {
  if (current === source) {
    return true;
  }

  if (current.length === 0) {
    return false;
  }
  let answer = false;
  if (current[0] === 'B') {
    answer = answer || f([...current.slice(1)].reverse().join(''));
  }

  if (current[current.length - 1] === 'A') {
    answer = answer || f(current.slice(0, current.length - 1));
  }

  return answer;
};

const main = () => {
  console.log(f(target) ? 1 : 0);
};

main();
