/**
 * @param {string} text
 * @param {string} brokenLetters
 * @return {number}
 */
var canBeTypedWords = function (text, brokenLetters) {
  const m = new Map();
  for (let i = 0; i < brokenLetters.length; i++) {
    const char = brokenLetters[i];
    m.set(char, 1);
  }

  return text
    .split(' ')
    .map((word) => {
      return [...word].some((h) => m.has(h)) ? 0 : 1;
    })
    .reduce((acc, cur) => acc + cur, 0);
};
