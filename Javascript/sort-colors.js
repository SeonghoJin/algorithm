/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    const m = new Map();
    for(let i = 0; i < nums.length; i++) {
        m.set(nums[i], (m.get(nums[i]) ?? 0) + 1);
    }

    for(let i = 0; i < nums.length; i++) {
        if(m.get(0) > 0) {
            nums[i] = 0;
            m.set(0, m.get(0) - 1);
            continue;
        }

        if(m.get(1) > 0) {
            nums[i] = 1;
            m.set(1, m.get(1) - 1);
            continue;
        }

        if(m.get(2) > 0) {
            nums[i] = 2;
            m.set(2, m.get(2) - 1);
            continue;
        }
    }

    return nums;
};