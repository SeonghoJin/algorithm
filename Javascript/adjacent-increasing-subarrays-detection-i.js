/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var hasIncreasingSubarrays = function (nums, k) {
  const newArr = Array.from({ length: nums.length });

  const diff = k - 1;
  for (let i = 0; i < newArr.length; i++) {
    newArr[i] = 1;

    if (nums[i] - nums[i - 1] > 0) {
      newArr[i] = newArr[i - 1] + 1;
    }

    if (
      newArr[i] - newArr[i - diff] >= diff &&
      newArr[i - diff - 1] - newArr[i - diff - 1 - diff] >= diff
    ) {
      return true;
    }
  }

  return false;
};
