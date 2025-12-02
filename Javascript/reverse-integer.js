/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
  const isMinuse = x < 0;

  const n = String(Math.abs(x));
  const t = Number(n.split('').reverse().join(''));

  const min = -Math.pow(2, 31);
  const max = Math.pow(2, 31) - 1;
  if (t < min || t > max) {
    return 0;
  }

  if (isMinuse && t !== 0) {
    return -t;
  }

  return t;
};
