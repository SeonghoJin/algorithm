function solution(heights) {
    var answer = [];
    heights.unshift(101);
    console.log(heights);
    
    var temp = [];
    
    temp.push(0);
    
    for(var i = 1; i < heights.length; i++){
        var hc = heights[i];
        var last = heights[temp[temp.length - 1]];
        
        while(last <= hc){
            temp.pop();
            last = heights[temp[temp.length-1]];
        }
        answer.push(temp[temp.length-1]);
        console.log(temp[temp.length-1]);
        temp.push(i);
    }
    
    return answer;
}