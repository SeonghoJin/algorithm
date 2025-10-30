function smallestNumber(n: number): number {
    let answer = 0;

    while( n  >= 1 ) {
        answer += 1;
        n/=2;
    }

    answer = Math.pow(2, answer) - 1;
    return answer;
};