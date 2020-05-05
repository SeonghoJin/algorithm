function solution(progresses, speeds) {
    var answer = [];
    
    var temp =[];
    var end = [];
    for(var i = 0; i <= 100; i++)temp[i] = 0;
    for(var i = 0; i < speeds.length; i++){
        var c = (100 - progresses[i] + speeds[i]-1)/speeds[i];
        c = parseInt(c);
        end[i] = c;
    }
    for(var i = 0; i < 100; i++){
        temp[i+1] += temp[i];
    }
   
    var start = -1;
    var sum = 0;
    for(var i = 0; i < speeds.length; i++){
        console.log(i);
        if(i == speeds.length - 1){
            answer.push(1);
            break;
        }
        var e = end[i];
        var k = 1;
        for(var j = i+1; j <= speeds.length; j++){
            if(speeds.length == j){
                i = j;
                break;
            }
            if(end[j] <= e){
                k++;
            }
            else{
                i = j-1;
                break;
            }
        }    
        
        answer.push(k);
    }
    
    return answer;
}