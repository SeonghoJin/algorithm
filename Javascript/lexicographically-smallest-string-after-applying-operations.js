/**
 * @param {string} s
 * @param {number} a
 * @param {number} b
 * @return {string}
 */
var findLexSmallestString = function(s, a, b) {
  const ss = new Set();

  const increase = (c) => {
    let ret = ""
    for(let i = 0; i < c.length; i ++) {
        if(i % 2 == 0) {
            ret+=c[i];
            continue;
        }
        const t = c[i];
        ret += ((Number(t) + a) % 10).toString();
    }
    return ret;
  }
  
  /**
   * @param {string} c
   */
  const rotate = (c) => {
    return c.substring(c.length - b, c.length) + c.substring(0, c.length - b);
  }
  
  const arr = [];
  let current = 0;

  arr.push(s);

  while(current < arr.length) {
    let cur = arr[current++];

    const inc = increase(cur);
    const rot = rotate(cur);

    if(!ss.has(inc)) {
        ss.add(inc);
        arr.push(inc)
    }

    if(!ss.has(rot)){
        ss.add(rot);
        arr.push(rot);
    }
  }
  return [...ss].sort().at(0)
};