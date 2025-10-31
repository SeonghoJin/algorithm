/**
 * @param {number[]} nums
 * @return {number[]}
 */
var getSneakyNumbers = function (nums) {
  const acc = nums.reduce(
    (acc, cur) => ({ ...acc, [cur]: (acc[cur] ?? 0) + 1 }),
    {}
  );

  return Object.entries(acc)
    .filter(([k, v]) => {
      return v >= 2;
    })
    .map(([k, v]) => Number(k));
};
