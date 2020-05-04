function solution(arrangement) {
    var answer = 0;
    var dep = 0;
    var new_str;
    for(var i = 0; i < arrangement.length; i++){
        
        if(arrangement[i] == '('){
            dep++;
        }
        else{
            if(i > 0 && arrangement[i-1] == '('){
                answer+= dep - 1;
                dep--;
            }
            else{
            answer+=1;
            dep--;
            }
        }
        
    }
    
    return answer;
}