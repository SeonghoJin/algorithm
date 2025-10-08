/**
 * @param {number[]} spells
 * @param {number[]} potions
 * @param {number} success
 * @return {number[]}
 */
var successfulPairs = function (spells, potions, success) {
  potions.sort((a, b) => (a - b > 0 ? 1 : -1));

  let s = potions.length;
  return spells.map((spell) => {
    let left = 0;
    let right = s;
    let mid = Math.floor((left + right) / 2);

    while (left < right) {
      if (potions[mid] * spell < success) {
        left = mid + 1;
      } else {
        right = mid;
      }
      mid = Math.floor((left + right) / 2);
    }

    return s - left;
  });
};
