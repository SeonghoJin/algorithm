/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[][]}
 */
var rangeAddQueries = function (n, queries) {
  const answer = Array.from({ length: n }, () =>
    Array.from({ length: n }, () => 0)
  );

  for (let i = 0; i < queries.length; i++) {
    const [x1, y1, x2, y2] = queries[i];

    for (let i = y1; i <= y2; i++) {
      answer[x1][i] += 1;
      if (x2 + 1 < n) {
        answer[x2 + 1][i] += -1;
      }
    }
  }

  for (let i = 1; i < n; i++) {
    for (let j = 0; j < n; j++) {
      answer[i][j] += answer[i - 1][j];
    }
  }

  return answer;
};
