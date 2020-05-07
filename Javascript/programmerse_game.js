function solution(n, t, m, p) {

    var len = t * m;
    var nlen = 0;
    var str = '';

    for(var i = 0; nlen <= len; i++){
        str += i.toString(n);
        nlen = str.length;
    }
    console.log(str);
    var answer = '';
    for(var i = 0; i < t; i++){
    answer += str[m*i+p-1];
    }
    return answer.toUpperCase();
}