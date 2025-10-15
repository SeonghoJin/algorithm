/**
 * @param {number[]} nums
 * @return {number}
 */
var maxIncreasingSubarrays = function (nums) {
  const newArr = Array.from({ length: nums.length });

  for (let i = 0; i < newArr.length; i++) {
    newArr[i] = 1;

    if (nums[i] - nums[i - 1] > 0) {
      newArr[i] = newArr[i - 1] + 1;
    }
  }

  const check = (start, k) => {
    const diff = k - 1;
    if (newArr[diff + start] - newArr[start] !== k - 1) {
      return false;
    }

    if (newArr[start + diff * 2 + 1] - newArr[start + diff + 1] !== k - 1) {
      return false;
    }

    return true;
  };

  const realCheck = (k) => {
    for (let i = 0; i < nums.length; i++) {
      if (check(i, k)) {
        return true;
      }
    }

    return false;
  };

  let left = 0;
  let right = nums.length;
  let mid = Math.floor((left + right) / 2);

  while (left < right) {
    if (realCheck(mid)) {
      left = mid + 1;
    } else {
      right = mid;
    }

    mid = Math.floor((left + right) / 2);
  }

  return mid - 1;
};
