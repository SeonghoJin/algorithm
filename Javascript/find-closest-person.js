/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {number}
 */
var findClosest = function (x, y, z) {
  const a = Math.abs(z - x);
  const b = Math.abs(z - y);

  if (a === b) return 0;
  return a > b ? 2 : 1;
};
