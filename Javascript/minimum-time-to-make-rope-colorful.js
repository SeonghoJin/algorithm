/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function (colors, neededTime) {
  let answer = 0;

  let st = [];

  for (let i = 0; i < colors.length; i++) {
    const color = colors[i];
    const time = neededTime[i];

    if (st.length > 0) {
      const last = st[st.length - 1];
      if (last[0] === color) {
        if (last[1] < time) {
          st.pop();
          answer += last[1];
          st.push([color, time]);
        } else {
          answer += time;
        }
      } else {
        st.push([color, time]);
      }
    } else {
      st.push([color, time]);
    }
  }

  return answer;
};
