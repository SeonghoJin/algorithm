var fs = require('fs');
 
fs.readFile('dev/stdin', 'utf8', function(err, data) {
    
    var input = data.split(' ');
    var N = input[0];
    var M = input[1];
    if(N == 1 || M == 1){
        console.log(1);
    }
    else if(N >= 3 && M >= 7){
        console.log(Math.max(M-2,4));
    }
    else if(N >= 3){
        console.log(Math.min(4,M));
    }
    else{
        console.log(Math.min(4,(M+1)/2));
    }
    

});