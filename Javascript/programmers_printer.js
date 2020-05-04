function solution(priorities, location) {
    var answer = 0;
    
    var count = [];
    for(var i = 0; i <= 10; i++){count[i] = 0;}
    var cur = 0;
    for(var i = 0; i < priorities.length; i++){
        count[priorities[i]]++;
        cur = Math.max(cur, priorities[i]);
        if(location == i){
            priorities[i] += 10;
        }
    }
    
    while(1){
        var here = priorities[0];
        priorities.shift();
        if(here-10 == cur){
            answer++;
            break;
        }
        else if(here == cur){
            answer++;
            count[here]--;
            if(count[here]==0){
                for(var i = cur-1; i > 0; i--){
                    if(count[i] != 0){
                        cur = i;
                        break;
                    }
                }
            }
            console.log(cur)
           
            
        }
        else{
            priorities.push(here);
        }
        console.log(priorities);
    }
    
    
    
    
    return answer;
}