/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
  let pointer = nums.length;

  const find = () => {
    pointer--;
    while (nums[pointer] === val) {
      pointer--;
    }
    return pointer;
  };

  for (let i = 0; i <= pointer; i++) {
    if (nums[i] === val) {
      const t = find();
      if (t > i) {
        const v = nums[t];
        nums[t] = nums[i];
        nums[i] = v;
      }
    }
  }

  return pointer + 1;
};
