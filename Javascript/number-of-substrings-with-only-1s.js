/**
 * @param {string} s
 * @return {number}
 */
var numSub = function(s) {
    const naturalSum = (n) => Math.floor(n * (n + 1) / 2)

    let answer = 0;
    let current = 0;
    for(let i = 0; i <= s.length; i++) {
        const char = s[i];
        
        if(s.length === i || char === '0') {
            answer += naturalSum(current);
            answer %= Math.pow(10, 9) + 7
            current = 0;
            continue;
        }

        current++;
        
    }

    return answer;
};