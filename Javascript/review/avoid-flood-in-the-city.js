/**
 * @param {number[]} rains
 * @return {number[]}
 */
var avoidFlood = function (rains) {
  const arr = [];
  const m = new Map();
  for (let i = 0; i < rains.length; i++) {
    const r = rains[i];
    if (r !== 0) {
      arr.push(-1);
      m.set(r, (m.get(r) ?? 0) + 1);
      if (m.get(r) >= 2) {
        return [];
      }
      continue;
    }
    let j = i;
    for (; j < rains.length; j++) {
      const vv = rains[j];
      if (vv === 0) continue;
      if (m.has(vv)) {
        break;
      }
    }
    const val = rains[j];
    if (val) {
      m.delete(val);
      arr.push(val);
    } else {
      arr.push(1);
    }
  }

  return arr;
};
