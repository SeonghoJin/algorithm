const a = {
  I: 1,
  IV: 4,
  IX: 9,
  V: 5,
  X: 10,
  XL: 40,
  XC: 90,
  CD: 400,
  CM: 900,
  L: 50,
  C: 100,
  D: 500,
  M: 1000,
};

/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let answer = 0;
  for (let i = 0; i < s.length; i++) {
    if (i + 1 < s.length) {
      const current = a[s.slice(i, i + 2)];
      if (current) {
        answer += current;
        i += 1;
        continue;
      }
    }

    const current = a[s[i]];
    if (current) {
      answer += current;
    }
  }
  return answer;
};
