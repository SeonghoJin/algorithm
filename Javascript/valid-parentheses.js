/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const arr = [];
  const t = {
    ')': '(',
    ']': '[',
    '}': '{',
  };
  const keys = Object.values(t);

  for (let i = 0; i < s.length; i++) {
    const current = s[i];
    if (keys.includes(current)) {
      arr.push(current);
      continue;
    }

    const open = t[current];
    if (arr[arr.length - 1] === open) {
      arr.pop();
    } else {
      arr.push(current);
    }
  }

  return arr.length === 0;
};
