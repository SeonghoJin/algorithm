function totalMoney(n) {
  const weeksCount = Math.floor(n / 7);
  const rest = n % 7;

  let answer =
    7 * Math.floor((weeksCount * (weeksCount - 1)) / 2) + 28 * weeksCount;
  for (let i = 0; i < rest; i++) {
    answer += i + 1 + weeksCount;
  }

  return answer;
}
