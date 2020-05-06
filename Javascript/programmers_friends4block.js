function check(board,a, b){
    var t = board[a][b];
    if(t == '2')return false;
    for(var i = 0; i < 2; i++){
        for(var j = 0; j < 2; j++){
            if(t != board[a+i][b+j])return false;
        }
    }
    
    return true;
}

function draw(board){
    var k = Array(board.length).fill(null).map(() => Array())
    
    for(var i = 0; i < board.length-1; i++){
        for(var j = 0; j < board[i].length-1; j++){
            if(check(board,i,j)){
                k[i][j] = k[i][j+1] = k[i+1][j] = k[i+1][j+1] = '1';
            }
        }
    }
    
    for(var i = 0; i < board.length; i++){
        for(var j = 0; j < board[i].length; j++){
           if(k[i][j] == '1'){
               board[i][j] = '1';
           }
        }
    }
 
}

function remove(board){
    
    var ret = 0;
    
    for(var j = 0; j < board[0].length; j++){
        for(var i = board.length-1; i >= 0; i--){
           if(board[i][j] != '1' && board[i][j] != '2'){
               var hi = i;
               while(1){
                   if(hi + 1 == board.length)break;
                   if(board[hi+1][j] != '1')break;
                   board[hi+1][j] = board[hi][j];
                   board[hi][j] = '1';
                   hi++;
               }
               
           }
            
        }
    }
    
    for(var i = 0; i < board.length; i++){
        for(var j = 0; j < board[0].length; j++){
            if(board[i][j] == '1'){
                ret++;
            board[i][j] = '2';
            }
            
        }
    }
    
    return ret;
}

function solution(m, n, board) {
    var answer = 0;
    
    for(var i = 0; i < board.length; i++){
        board[i] = board[i].split('');
    }
    
    while(1){
        draw(board);
        var temp = remove(board);
         if(temp == 0)break;
        answer += temp;
    }
    
    return answer;
}