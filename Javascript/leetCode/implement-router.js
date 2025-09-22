class Q {
  constructor(size) {
    this.size = size ?? Number.MAX_VALUE;
    this.start = 0;
    this.end = 0;
    this.array = Array.from({ length: size }, () => null);
  }

  add = (item) => {
    let ret = null;
    if (this.end - this.start >= this.size) {
      const item = this.array[this.start];
      this.start++;
      ret = item;
    }
    this.array[this.end++] = item;
    return ret;
  };

  first = () => {
    return this.array[this.start];
  };

  pop = () => {
    return this.start++;
  };

  get = () => {
    return this.array.slice(this.start, this.end);
  };

  lowerBound = (callback) => {
    let start = this.start;
    let end = this.end;

    while (start < end) {
      let mid = Math.floor((start + end) / 2);
      const val = this.array[mid];
      if (callback(val)) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }

    return start;
  };
}

/**
 * @param {number} memoryLimit
 */
var Router = function (memoryLimit) {
  this.memoryLimit = memoryLimit;
  this.map = new Map();
  this.q = new Q(memoryLimit);
  this.mq = new Map();
};

const createKey = (source, destination, timestamp) => {
  return `${source}-${destination}-${timestamp}`;
};

/**
 * @param {number} source
 * @param {number} destination
 * @param {number} timestamp
 * @return {boolean}
 */
Router.prototype.addPacket = function (source, destination, timestamp) {
  if (this.map.get(createKey(source, destination, timestamp))) {
    return false;
  }
  this.map.set(createKey(source, destination, timestamp), true);
  const deleted = this.q.add([source, destination, timestamp]);
  if (deleted) {
    const dq = this.mq.get(deleted[1]);
    dq.pop();
    this.mq.set(deleted[1], dq);
    this.map.set(createKey(...deleted), false);
  }
  const dq = this.mq.get(destination) ?? new Q();
  dq.add([source, destination, timestamp]);
  this.mq.set(destination, dq);
  return true;
};

/**
 * @return {number[]}
 */
Router.prototype.forwardPacket = function () {
  const item = this.q.first();
  if (!item) {
    return [];
  }
  const [source, destination, timestamp] = item;
  this.map.delete(createKey(source, destination, timestamp));
  this.q.pop();
  const dq = this.mq.get(destination);
  dq.pop();
  this.mq.set(destination, dq);
  return item;
};

/**
 * @param {number} destination
 * @param {number} startTime
 * @param {number} endTime
 * @return {number}
 */
Router.prototype.getCount = function (destination, startTime, endTime) {
  const mq = this.mq.get(destination);
  const a1 =
    mq?.lowerBound(([_, __, time]) => {
      return time >= startTime;
    }) ?? 0;
  const a2 =
    mq?.lowerBound(([_, __, time]) => {
      return time > endTime;
    }) ?? 0;

  return a2 - a1;
};

/**
 * Your Router object will be instantiated and called as such:
 * var obj = new Router(memoryLimit)
 * var param_1 = obj.addPacket(source,destination,timestamp)
 * var param_2 = obj.forwardPacket()
 * var param_3 = obj.getCount(destination,startTime,endTime)
 */
