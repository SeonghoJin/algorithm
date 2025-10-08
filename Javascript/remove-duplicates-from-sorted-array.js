/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
  let pointer = 1;
  for (let i = 1; i < nums.length; i++) {
    if (nums[i] > nums[pointer - 1]) {
      nums[pointer] = nums[i];
      pointer++;
    }
  }

  const len = nums.length;

  for (let i = pointer; i < len; i++) {
    nums.pop();
  }
};
