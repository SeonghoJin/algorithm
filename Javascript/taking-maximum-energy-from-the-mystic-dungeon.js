/**
 * @param {number[]} energy
 * @param {number} k
 * @return {number}
 */
var maximumEnergy = function (energy, k) {
  let memo = Array.from({ length: energy.length }).fill(-1);
  const f = (start) => {
    if (memo[start] != -1) {
      return memo[start];
    }

    let ans = energy[start];
    const next = start + k;
    if (next < energy.length) {
      ans += f(next);
    }

    memo[start] = ans;
    return ans;
  };

  let answer = energy[energy.length - 1];

  for (let i = 0; i < energy.length; i++) {
    answer = Math.max(answer, f(i));
  }

  return answer;
};
