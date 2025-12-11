/**
 * @param {number} n
 * @param {number[][]} buildings
 * @return {number}
 */
var countCoveredBuildings = function(n, buildings) {
    let y = new Map();
    let x = new Map();

    for (let i = 0; i < buildings.length; i++) {
        const [_x, _y] = buildings[i];
        const arr = x.get(_x) ?? [];
        arr.push(_y)
        x.set(_x, arr);

        const arr2 = y.get(_y) ?? [];
        arr2.push(_x);
        y.set(_y, arr2);
    }

    const lowerBound = (arr, x) => {
        let left = 0;
        let right = arr.length;
        let mid = Math.floor((left + right) / 2);

        while (left + 1 < right) {
            if(arr[mid] > x) {
                right = mid;
            } else {
                left = mid;
            }

            mid = Math.floor((left + right) / 2);
        }

        return left;
    }  


    for (const arr of x.values()) {
        arr.sort((a, b) => a - b);
    }
    for(const arr of y.values()) {
        arr.sort((a, b) => a - b);
    }

    let answer = 0;
    for(let i = 0; i < buildings.length; i++) {
        const [_x, _y] = buildings[i];
        const xArr = x.get(_x);
        const yArr = y.get(_y);
        const xCount = xArr.length;
        const yCount = yArr.length;

        const xi = lowerBound(xArr, _y);
        const yi = lowerBound(yArr, _x);

        if(0 < xi && xi < xCount - 1 && 0 < yi && yi < yCount - 1) {
            answer++;
        }
    }
    
    return answer;
};