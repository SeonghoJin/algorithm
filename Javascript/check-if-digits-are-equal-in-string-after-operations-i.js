/**
 * @param {string} s
 * @return {boolean}
 */
var hasSameDigits = function (s) {
  const f = (t) => {
    let str = '';
    for (let i = 0; i < t.length - 1; i++) {
      str += ((Number(t[i]) + Number(t[i + 1])) % 10).toString();
    }
    return str;
  };

  const check = (t) => {
    for (let i = 0; i < t.length - 1; i++) {
      if (t[i] != t[i + 1]) {
        return false;
      }
    }
    return true;
  };

  let cur = s;
  while (!check(cur) && cur.length > 1) {
    cur = f(cur);
  }
  return check(cur) && cur.length > 1;
};
