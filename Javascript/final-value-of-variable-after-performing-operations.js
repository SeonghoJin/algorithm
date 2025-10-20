/**
 * @param {string[]} operations
 * @return {number}
 */
var finalValueAfterOperations = function (operations) {
  return operations
    .map((opeartion) => {
      switch (opeartion) {
        case '--X':
        case 'X--':
          return -1;
        case '++X':
        case 'X++':
          return 1;
      }
    })
    .reduce((acc, cur) => acc + cur, 0);
};
