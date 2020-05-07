var answer = 0;

function count(t){
    return t.toString(2).match(/1/g).length;   
}
function solution(relation) {
    var dp = Array(1024).fill(0);
    var w = relation[0].length; 
    var h = relation.length;
    var cand = Array(w+1).fill(null).map(() => Array());
    var c = Math.pow(2, w);
    console.log(w);
    console.log(h);
    console.log(c);
    for(var i = 1; i < c; i++){
        
        var flag = true; 
        var temp = [];
        for(var j = 0; j < h; j++){
            var key = '';
            for(var k = 0; k < w; k++){
                //console.log(c & (1 << k));
                if(i & (1 << k)){
                    key += relation[j][k];
                }
            }
            //console.log(key);
            if(temp[key] == 1){
                flag = false
                break;
            }
            else{
                temp[key] = 1;
            }
        }
        if(flag){
            //console.log("밑은 count");
            //console.log(count(i));
            //console.log(i);
            cand[count(i)].push(i);    
        }
    }
    console.log(cand);
    for(var i = w-1; i >= 0; i--){
        for(var j = 0; j < cand[i].length; j++){
            var here = cand[i][j];
            for(var k = 0; k < cand[i+1].length; k++){
                var next = cand[i+1][k];
                //console.log(here + " " + next);
                if((here & next) == here){
                    cand[i+1].splice(k,1);
                    k--;
                }
            }
        }
        
    }
    var answer = 0;
    for(var i = 1; i <= w; i++){
        answer += cand[i].length;
    }
    return answer;
}