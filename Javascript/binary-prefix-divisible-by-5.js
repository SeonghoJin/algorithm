
/**
 * @param {number[]} nums
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(nums) {
    let answer = []; 
    let current = 0;
    for (let i = 0; i < nums.length; i++) {
        current += nums[i];
        answer.push(current % 5 === 0);

        current *= 2;
        current %= 1000;
    }
    return answer;
};