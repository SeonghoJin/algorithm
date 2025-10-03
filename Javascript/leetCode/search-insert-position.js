/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
  const len = nums.length;
  let left = 0;
  let right = len;
  let mid = Math.floor(len / 2);

  while (left < right) {
    if (nums[mid] <= target) {
      left = mid + 1;
    } else {
      right = mid;
    }
    mid = Math.floor((left + right) / 2);
  }

  return left;
};
