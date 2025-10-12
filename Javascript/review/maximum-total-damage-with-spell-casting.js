/**
 * @param {number[]} power
 * @return {number}
 */
var maximumTotalDamage = function (power) {
  power.sort((a, b) => (a - b > 0 ? 1 : -1));
  const mp = new Map();

  for (let i = 0; i < power.length; i++) {
    const p = power[i];
    mp.set(p, (mp.get(p) ?? 0) + 1);
  }

  const arr = [...mp].sort((a, b) => (a[0] - b[0] > 0 ? 1 : -1));
  console.log(arr);
  let dp = Array.from({ length: arr.length }).fill(-1);

  const f = (start) => {
    if (dp[start] !== -1) {
      return dp[start];
    }
    let [p, cnt] = arr[start];
    let answer = p * cnt;
    for (let i = start + 1; i < arr.length; i++) {
      const diff = Math.abs(arr[start][0] - arr[i][0]);

      if (diff === 0 || diff > 2) {
        answer = Math.max(answer, arr[start][0] * arr[start][1] + f(i));
      }
    }

    dp[start] = answer;
    return answer;
  };

  let answer = 0;

  for (let i = 0; i < arr.length; i++) {
    answer = Math.max(answer, f(i));
  }

  return answer;
};
