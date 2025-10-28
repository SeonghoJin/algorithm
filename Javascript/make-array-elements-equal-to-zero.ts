function countValidSelections(nums: number[]): number {
    const n = nums.length;
    const leftSums: number[] = Array.from({ length: nums.length });
    const rightSums: number[] = Array.from({ length: nums.length });


    for (let i = 0; i < n; i++) {
        leftSums[i] = nums[i] + (leftSums[i - 1] ?? 0);
    }

    for (let i = n - 1; i >= 0; i--) {
        rightSums[i] = nums[i] + (rightSums[i + 1] ?? 0);
    }

    let answer = 0;

    for (let i = 0; i < n; i++) {
        if (nums[i] === 0) {
            const diff = Math.abs((leftSums[i - 1] ?? 0) - (rightSums[i + 1] ?? 0));

            if (diff === 0) {
                answer += 2;
            }

            if (diff === 1) {
                answer += 1;
            }
        }
    }

    return answer;
};