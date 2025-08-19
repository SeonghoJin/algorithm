/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  for (let i = 0; i < strs[0].length; i++) {
    let current = 0;
    const currentChar = strs[0][i];
    for (let j = 0; j < strs.length; j++) {
      if (currentChar === strs[j][i]) {
        current++;
      }
    }

    if (current !== strs.length) {
      return strs[0].slice(0, i);
    }
  }

  return strs[0];
};
