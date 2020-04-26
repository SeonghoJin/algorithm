function solution(board)
{
    var answer = 0;
    
    var y = board.length;
    var x = board[0].length;

    var board_row = new Array(y);
    var board_column = new Array(y);
    for(var i = 0; i < y; i++){
        board_row[i] = new Array(x);
        board_column[i] = new Array(x);
    }
    
    for(var i = 0; i < y; i++){
        for(var j = 0; j < x; j++){
            if(j >= 1)board_row[i][j] = board_row[i][j-1] + board[i][j];
            else{board_row[i][j] = board[i][j];}
        }
    }
     for(var i = 0; i < x; i++){
        for(var j = 0; j < y; j++){
            if(j >= 1)board_column[j][i] = board_column[j-1][i] + board[j][i];
            else{board_column[j][i] = board[j][i];}
        }
    }
    
  
    for(var i = 0; i < y; i++){
        for(var j = 0; j < x; j++){
            
            if(board[i][j] == 0)continue;
            answer = Math.max(1,answer);
           // console.log(i + " " + j)
            var sy = i+1;
            var sx = j+1;
           // console.log(i +" " + j + " " + sy + " " + sx);
            var width = 2;
            var sum = 1;
           // console.log(i +" " + j + " " + sy + " " + sx);
            while(sy < y && sx < x){
                sum += board_row[sy][sx] - (j - 1 >= 0 ? board_row[sy][j-1] : 0) +board_column[sy][sx] - (i-1 >= 0 ? board_column[i-1][sx] : 0)- board[sy][sx];
               // console.log(board_row[sy][sx] + " " +(j - 1 >= 0 ? board_row[sy][j-1] : 0)  + " " + board_column[sy][sx] + " " + (i-1 >= 0 ? board_column[i-1][sx] : 0)+" " +  board[sy][sx]);
             //  console.log(sum);
                if(width*width == sum){
                   
                    if(answer < sum){
                        answer = sum;
                    }
                    width++
                    sx++;
                    sy++;
                }
                else{
                    break;
                }
            }
        
        }
    }
    return answer;
}