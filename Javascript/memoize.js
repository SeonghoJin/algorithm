/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {
    const cache = new Map();
    

    return function(...args) {
          const cacheKey = JSON.stringify(args);
          if(cache.has(cacheKey)){
            return cache.get(cacheKey);
          }

          const t = fn(...args);
          cache.set(cacheKey, t);
          return t;
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */