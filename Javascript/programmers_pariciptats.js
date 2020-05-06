function solution(n,a,b)
{
    var answer = 3;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    console.log('Hello Javascript')
    
    for(var i = 1; i <= 20; i++){
        var t = Math.pow(2,i);
        if(parseInt((a-1)/t) == parseInt((b-1)/t)){
            return i;
        }
    }
    
    return answer;
}