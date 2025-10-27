function numberOfBeams(bank: string[]): number {
  const countOne = (str: string) => {
    let acc = 0;

    for (let i = 0; i < str.length; i++) {
      acc += str[i] === '1' ? 1 : 0;
    }

    return acc;
  };

  const res = bank.map(countOne).filter((num) => num !== 0);
  let ans = 0;
  for (let i = 0; i < res.length - 1; i++) {
    ans += res[i] * res[i + 1];
  }
  return ans;
}
