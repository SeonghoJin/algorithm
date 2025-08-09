// @ts-check
const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : './Javascript/dev/stdin.txt')
  .toString()
  .trim()
  .split(/\s+/)
  .map(Number);

const main = () => {
  let n = input[0];

  function countWaysDP(N) {
    const total = 3 * N;
    // BigInt로 해두면 큰 N에서도 안전
    const dp = Array.from({ length: total + 1 }, () =>
      Array(total + 1).fill(0n)
    );
    dp[0][0] = 1n;

    for (let i = 0; i <= total; i++) {
      for (let j = 0; j <= total - i; j++) {
        const cur = dp[i][j];
        if (cur === 0n) continue;
        const t = i + j;
        if (t === total) continue;

        const needLunch = t % 3 === 1;

        const leftIsLunch = i % 3 === 1;
        const rightIndex = total - 1 - j;
        const rightIsLunch = rightIndex % 3 === 1;

        // 왼쪽 선택
        if ((needLunch && leftIsLunch) || (!needLunch && !leftIsLunch)) {
          dp[i + 1][j] += cur;
        }
        // 오른쪽 선택
        if ((needLunch && rightIsLunch) || (!needLunch && !rightIsLunch)) {
          dp[i][j + 1] += cur;
        }
      }
    }
    console.log(dp);
    return dp[total][0]; // i+j=total인 모든 상태가 합쳐져 여기로 도달함
  }
  console.log(countWaysDP(n));
};

main();
