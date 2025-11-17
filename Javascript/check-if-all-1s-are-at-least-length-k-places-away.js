/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var kLengthApart = function (nums, k) {
  return nums
    .map((num, i) => {
      if (num === 1) {
        return i;
      }

      return undefined;
    })
    .filter((idx) => idx !== undefined)
    .reduce(
      (acc, cur) => {
        const { answer, value } = acc;
        return {
          answer: Math.abs(value - cur) > k && answer,
          value: cur,
        };
      },
      {
        answer: true,
        value: Number.MIN_SAFE_INTEGER,
      }
    ).answer;
};
