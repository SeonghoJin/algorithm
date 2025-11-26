/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  const arr = [
    [],
    [],
    ['a', 'b', 'c'],
    ['d', 'e', 'f'],
    ['g', 'h', 'i'],
    ['j', 'k', 'l'],
    ['m', 'n', 'o'],
    ['p', 'q', 'r', 's'],
    ['t', 'u', 'v'],
    ['w', 'x', 'y', 'z'],
  ];

  const answer = [];

  const f = (current, temp) => {
    if (current === digits.length) {
      answer.push(temp);
      return;
    }

    let cur = temp;
    const cand = arr[Number(digits[current])];

    for (let i = 0; i < cand.length; i++) {
      f(current + 1, cur + cand[i]);
    }
  };

  f(0, '');

  return answer;
};
