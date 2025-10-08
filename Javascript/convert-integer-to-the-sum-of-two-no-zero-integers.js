/**
 * @param {number} n
 * @return {number[]}
 */
var getNoZeroIntegers = function (n) {
  const hasZero = (value) => {
    const str = String(value);
    for (let i = 0; i < str.length; i++) {
      if (str[i] === '0') {
        return true;
      }
    }
    return false;
  };

  for (let i = 1; i < n; i++) {
    const a = i;
    const b = n - i;
    if (hasZero(a) || hasZero(b)) {
      continue;
    }
    return [a, b];
  }
};
