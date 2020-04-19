var fs = require('fs');
 
fs.readFile('dev/stdin', 'utf8', function(err, data) {
    
    var input = data.split(' ');
    var N = input[0];
    var M = input[1];
    if(N == 1 || M == 1){
        console.log(1);
    }
    else if(N == 2){
        console.log(Math.min(4,(M+1)/2));
    }
    else if(N >= 3 && M >= 6){
        console.log(M-2);
    }
    else{
        console.log(Math.min(4,M));
    }
    
    

});