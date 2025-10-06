/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
  let acc = 1;

  for (let i = digits.length - 1; i >= 0; i--) {
    digits[i] += acc;
    acc = Math.floor(digits[i] / 10);
    digits[i] %= 10;
  }
  if (acc > 0) {
    return [1, ...digits];
  }

  return digits;
};
