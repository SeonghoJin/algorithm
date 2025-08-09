// @ts-check

const input = require('fs')
  .readFileSync(process.platform === 'linux' ? 0 : './Javascript/dev/stdin.txt')
  .toString()
  .trim()
  .split(/\r?\n/);

const main = () => {
  const current = input[1];
  const n = current.length;
  const arrD = Array.from({ length: n }, () => 0);
  const arrK = Array.from({ length: n }, () => 0);
  const arrS = Array.from({ length: n }, () => 0);
  const arrH = Array.from({ length: n }, () => 0);

  for (let i = arrH.length - 1; i >= 0; i--) {
    if (current[i] === 'H') {
      arrH[i]++;
    }

    if (i + 1 <= arrH.length - 1) {
      arrH[i] += arrH[i + 1];
    }

    if (i <= arrS.length - 2) {
      if (current[i] === 'S') {
        arrS[i]++;
      }

      arrS[i] *= arrH[i + 1];
      arrS[i] += arrS[i + 1];
    }

    if (i <= arrS.length - 3) {
      if (current[i] === 'K') {
        arrK[i]++;
      }

      arrK[i] *= arrS[i + 1];
      arrK[i] += arrK[i + 1];
    }

    if (i <= arrD.length - 4) {
      if (current[i] === 'D') {
        arrD[i]++;
      }

      arrD[i] *= arrK[i + 1];
      arrD[i] += arrD[i + 1];
    }
  }

  console.log(arrD[0]);
};

main();
