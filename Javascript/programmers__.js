function solution(board, moves) {
    var answer = 0;
    
    var t = Array(board.length).fill(null).map(() => Array());
    var cur = Array(board.length).fill(0);
    
    for(var i = 0; i < board.length; i++){
        for(var j = 0; j < board[i].length; j++){
            if(board[i][j] != 0){
                t[j].push(board[i][j]);
            }
        }
    }
    //console.log(t);
    var temp = [];
    
    for(var i = 0; i < moves.length; i++){
        var k = t[moves[i]-1][cur[moves[i]-1]++]
        if(k != undefined){
            temp.push(k)
        }
    }
    var st = [];
    console.log(temp);
    for(var i = 0; i < temp.length; i++){
        if(st.length == 0 || st[st.length-1] != temp[i]){
            st.push(temp[i]);
        }
        else{
            answer++;
            st.pop();
        }
    }
    
    return answer*2;
}