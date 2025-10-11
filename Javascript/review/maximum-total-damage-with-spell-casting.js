/**
 * @param {number[]} power
 * @return {number}
 */
var maximumTotalDamage = function(power) {
    power.sort((a, b) => a - b > 0 ? 1: -1);

    let dp = Array.from({length: power.length}).fill(-1);
    
    const f = (start) => {
        if(dp[start] !== -1){
            return dp[start];
        }

        let answer = power[start];
        for(let i = start + 1; i < power.length; i++) {
            const diff = Math.abs(power[start] - power[i]);

            if(diff === 0 || diff > 2) {
                answer = Math.max(answer, power[start] + f(i));
            }
        }
        dp[start] = answer;
        return answer;
    }

    
    let answer = 0;

    for (let i = 0; i < power.length; i++) {
        answer = Math.max(answer, f(i));
    }

    return answer;
};