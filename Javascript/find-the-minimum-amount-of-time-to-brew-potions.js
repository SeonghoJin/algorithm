/**
 * @param {number[]} skill
 * @param {number[]} mana
 * @return {number}
 */
var minTime = function (skill, mana) {
  const arr = [];
  let answer = 0;
  for (let i = 0; i < mana.length; i++) {
    const t = [];
    for (let j = 0; j < skill.length; j++) {
      t.push(mana[i] * skill[j] + (t[j - 1] ?? 0));
    }
    arr.push(t);

    if (i > 0) {
      for (let j = 0; j < t.length; j++) {
        answer = Math.max(answer, arr[i - 1][j] - (arr[i][j - 1] ?? 0));
      }
    }
    for (let j = 0; j < t.length; j++) {
      arr[i][j] += answer;
    }
  }

  return arr[mana.length - 1][skill.length - 1];
};
