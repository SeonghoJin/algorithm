/**
 * @param {number[]} complexity
 * @return {number}
 */
var countPermutations = function (complexity) {
  const first = complexity[0];
  const zeroCount = complexity.filter((v) => v > first);

  if (zeroCount.length !== complexity.length - 1) {
    return 0;
  }

  const factory = (num) => {
    let answer = 1;
    for (let i = 1; i <= num; i++) {
      answer *= i;
      answer %= 1e9 + 7;
    }
    return answer;
  };

  return factory(zeroCount.length);
};
