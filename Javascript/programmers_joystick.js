function solution(name) {
    var answer = 0;
    var str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    var k = [];
    for(var i = 0; i < name.length; i++){
        if(name[i] != 'A')k.push(i);
           var t = 0;
        for(var j = 0; j < 26; j++){
            if(str[j] == name[i]){
                t = j;
                break;
            }
        }
        
        answer += Math.min(t, 26 - t);
    }
    
    console.log(k);
    var start = 0;
    while(k.length != 0){
        var a = Math.min(Math.abs(start - k[0]), name.length-Math.abs(start-k[0]));    
        var b = Math.min(Math.abs(start- k[k.length-1]), name.length - Math.abs(start-k[k.length-1]));
        if(a <= b){
            start = k[0];
            answer += a;
            k.shift();
        }
        else{
            start = k[k.length-1];
            answer += b;
            k.pop();
        }
    }
    return answer
}