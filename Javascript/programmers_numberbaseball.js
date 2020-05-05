function check(a,baseball){
    var f = true;
    var count = [];
    a = String(a);
    for(var j = 0; j < 10; j++){
        count[j] = 0;
    }
    
    for(var i = 0; i < 3; i++){
        count[a[i]]++;
    }
   // console.log(count);
    for(var i = 0; i < baseball.length; i++){
        var target = baseball[i][0];
        var str = baseball[i][1];
        var ball = baseball[i][2];
       // console.log(target);
        target = String(target);
        var cstr = 0;
        for(var j = 0; j < 3; j++){
            if(a[j] == target[j]){
                cstr++;
            }
        }
        //console.log(cstr);
        //if(str != cstr)return false;
        
        var cball = 0;
        
        var ballc = [];
        for(var j = 0; j < 10; j++){
            ballc[j] = 0;
        }
        for(var j = 0; j < 3; j++){
            ballc[target[j]]++;
        }
        for(var j = 1; j < 10; j++){
            if(ballc[j] > 0 && count[j] > 0){
                cball++;
            }
        }
        cball -= cstr;
        
        console.log(cball + " " + cstr);
        
      // if(cball != ball)return false;
    }
    return true;
}


function solution(baseball) {
    var answer = 0;
    
    /*for(var i = 1; i < 1000; i++){
        if(check(i,baseball)){
            answer++;
            console.log(i);
        }
    }*/
    check(312,baseball);
    return answer;
}