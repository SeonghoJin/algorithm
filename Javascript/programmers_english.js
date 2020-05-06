function solution(n, words) {
    var answer = [];
    var used ={};
    var check = 987654321;
    words.forEach((x, i) =>{
        if(used.hasOwnProperty(x)){
            check = Math.min(check,i);
        }
        else{
            used[x] = 1;
        }
        if(i > 0 && words[i-1][words[i-1].length-1] != words[i][0]){
            check =Math.min(check,i);
        }
        
    })
    answer = [0, 0];
    if(check != 987654321){
        answer[0] = parseInt((check)%n + 1);
        answer[1] = parseInt((check)/n + 1)
    }
    return answer;
}