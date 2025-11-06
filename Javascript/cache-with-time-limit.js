var TimeLimitedCache = function () {
  this.cachedCount = 0;
  this.m = new Map();
  this.timeoutId = new Map();
};

/**
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function (key, value, duration) {
  if (this.m.has(key)) {
    const beforeTimeoutId = this.timeoutId.get(key);
    clearInterval(beforeTimeoutId);
    this.m.set(key, value);
    const id = setTimeout(() => {
      this.m.delete(key);
      this.cachedCount--;
      this.timeoutId.delete(key);
    }, duration);
    this.timeoutId.set(key, id);
    return true;
  }
  this.m.set(key, value);
  this.cachedCount++;
  const id = setTimeout(() => {
    this.m.delete(key);
    this.cachedCount--;
    this.timeoutId.delete(key);
  }, duration);
  this.timeoutId.set(key, id);
  return false;
};

/**
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function (key) {
  if (!this.m.has(key)) {
    return -1;
  }

  return this.m.get(key);
};

/**
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function () {
  return this.cachedCount;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */
