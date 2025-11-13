/**
 * @param {string} s
 * @return {number}
 */
var maxOperations = function (s) {
  const n = s.length;

  let cur = s[n - 1] === '0' ? 1 : 0;
  let answer = 0;
  for (let i = n - 2; i >= 0; i--) {
    if (s[i] === '0' && s[i + 1] === '1') {
      cur++;
    }

    if (s[i] === '1') {
      answer += cur;
    }
  }
  return answer;
};
