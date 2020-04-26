var fs = require('fs');
 
fs.readFile('dev/stdin', 'utf8', function(err, data) {
        
    var input = data.split('\n');
    var N = input[0];
    var c = 0;
    var ans = 1;
    for(var i = 1; i <= N; i++){
        var temp = 0;
        var visit = new Array(N+1);
        
        for(var j = 0; j < 5; j++){
            for(var k = 1; k <= N; k++){
                if(visit[k])continue;
                if(k == i)continue;
                if(input[i].split(' ')[j] == input[k].split(' ')[j]){
                   visit[k] = true;
                   temp++;
                   
                } 
            }
        }
        if(c < temp){
            c = temp;
            ans = i;
        }
    }
  
    console.log(ans);
});