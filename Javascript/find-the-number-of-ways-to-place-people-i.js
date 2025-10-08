/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfPairs = function (points) {
  let answer = 0;
  const n = points.length;

  /**
   * @param {number} idx
   */
  const check = (idx, l, r) => {
    const [cx, cy] = points[idx];

    const [lx, ly] = points[l];
    const [rx, ry] = points[r];
    const [minx, miny] = [Math.min(lx, rx), Math.min(ly, ry)];
    const [maxx, maxy] = [Math.max(lx, rx), Math.max(ly, ry)];

    if (minx <= cx && cx <= maxx) {
      if (miny <= cy && cy <= maxy) {
        return true;
      }
    }

    return false;
  };

  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (i === j) continue;
      const [ix, iy] = points[i];
      const [jx, jy] = points[j];

      if (ix <= jx && iy >= jy) {
        console.log(i, j);
        let flag = true;
        for (let k = 0; k < n; k++) {
          if (k === i || k === j) {
            continue;
          }

          if (check(k, i, j)) {
            flag = false;
            continue;
          }
        }
        if (flag) answer++;
      }
    }
  }

  return answer;
};
