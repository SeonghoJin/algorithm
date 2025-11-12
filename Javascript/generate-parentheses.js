/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function (n) {
  const answer = [];

  let temp = '';

  const isValid = () => {
    const stack = [];

    for (let i = 0; i < temp.length; i++) {
      const char = temp[i];

      if (char === '(') {
        stack.push(char);
      } else {
        stack.pop();
      }
    }

    return stack.length === 0;
  };

  const f = (left, right) => {
    if (left + right === 2 * n) {
      if (isValid()) {
        answer.push(temp);
      }
      return;
    }

    if (left < n) {
      temp += '(';
      f(left + 1, right);
      temp = temp.slice(0, temp.length - 1);
    }

    if (right < n) {
      temp += ')';
      f(left, right + 1);
      temp = temp.slice(0, temp.length - 1);
    }
  };
  f(0, 0);
  return answer;
};
