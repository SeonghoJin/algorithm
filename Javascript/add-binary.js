/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
  const m = Math.max(a.length, b.length);

  let acc = 0;
  let answer = '';
  for (let i = 0; i < m; i++) {
    const c = Number.parseInt(a[a.length - i - 1] ?? '0');
    const cc = Number.parseInt(b[b.length - i - 1] ?? '0');
    const t = c + cc + acc;
    answer += t % 2;
    acc = Math.floor(t / 2);
  }

  if (acc) {
    answer += acc;
  }

  return [...answer].reverse().join('');
};
