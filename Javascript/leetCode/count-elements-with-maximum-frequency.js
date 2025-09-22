/**
 * @param {number[]} nums
 * @return {number}
 */
var maxFrequencyElements = function (nums) {
  let ret = 0;
  const obj = nums.reduce(
    (acc, cur) => ({
      ...acc,
      [cur]: (acc[cur] ?? 0) + 1,
    }),
    {}
  );
  console.log(obj);
  Object.values(obj).forEach((v) => {
    ret = Math.max(ret, v);
  });
  let answer = 0;
  Object.entries(obj).forEach(([k, v]) => {
    console.log(k, v);
    if (v === ret) {
      answer += v;
    }
  });
  return answer;
};
