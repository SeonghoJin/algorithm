/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
var findXSum = function (nums, k, x) {
  const answer = [];
  const m = new Map();
  let max_cur = [];

  const replace = (num) => {
    if (max_cur.includes(num)) {
      return;
    }
    if (max_cur.length <= x - 1) {
      max_cur.push(num);
      return;
    }

    max_cur.push(num);
    max_cur.sort((a, b) => {
      if (m.get(a) === m.get(b)) {
        return a < b ? 1 : -1;
      }

      return m.get(a) < m.get(b) ? 1 : -1;
    });
    max_cur.pop();
  };
  for (let i = 0; i < nums.length; i++) {
    const num = nums[i];
    m.set(num, (m.get(num) ?? 0) + 1);
    if (i - k >= 0) {
      const minus = nums[i - k];
      m.set(minus, m.get(minus) - 1);
    }
    replace(num);

    if (i >= k - 1) {
      console.log(max_cur, m);
      answer.push(
        max_cur
          .map((c) => {
            return c * m.get(c);
          })
          .reduce((acc, cur) => acc + cur, 0)
      );
    }
  }

  return answer;
};
