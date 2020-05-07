var cur = 27;
function solution(msg) {
    var m = {};
    var t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for(var i = 1; i <= 26; i++){
        m[t[i-1]] = i;
    }
    var answer = [];
    
    for(var i = 0; i < msg.length; i++){
        var k = 0;
        var key = '';
        while(1){
            if(m[key + msg[i+k]] == undefined){
                answer.push(m[key]);
                m[key + msg[i+k]] = cur++;
                break;
            }
            key += msg[i+k];
            k++;
        }
        i+=k-1;
    }
    console.log(answer);
    return answer;
}