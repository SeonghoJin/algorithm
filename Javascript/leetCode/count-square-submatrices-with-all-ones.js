/**
 * @param {number[][]} matrix
 */
const getLang = (matrix, startY, startX, endY, endX) => {
  let value = 0;

  value += matrix[endY][endX];

  if (startY - 1 >= 0) {
    value -= matrix[startY - 1][endX];
  }

  if (startX - 1 >= 0) {
    value -= matrix[endY][startX - 1];
  }

  if (startY - 1 >= 0 && startX - 1 >= 0) {
    value += matrix[startY - 1][startX - 1];
  }
  return value;
};

/**
 * @param {number[][]} matrix
 * @return {number}
 */
var countSquares = function (matrix) {
  const N = matrix.length;
  const M = matrix[0].length;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (i - 1 >= 0) {
        matrix[i][j] += matrix[i - 1][j];
      }

      if (j - 1 >= 0) {
        matrix[i][j] += matrix[i][j - 1];
      }

      if (i - 1 >= 0 && j - 1 >= 0) {
        matrix[i][j] -= matrix[i - 1][j - 1];
      }
    }
  }

  let answer = 0;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      let side = 0;

      while (i + side < N && j + side < M) {
        const val = getLang(matrix, i, j, i + side, j + side);
        if (val === (side + 1) * (side + 1)) {
          answer++;
        }

        side++;
      }
    }
  }

  return answer;
};
