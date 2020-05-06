function compare(a, b){
    var len1 = a.length;
    var len2 = b.length;
    var len = Math.min(len1, len2);
   // console.log(len)
   // console.log(a + " " + b)
    for(var i = 0; i < len; i++){
        if(a[i] < b[i]){
            return 1;
        }
        else if(a[i] > b[i]){
            return -1;
        }
    }
   // console.log(len1 + " " + len2)
    if(len1 == len2)return 0;
    
    if(len1 > len2){
        return compare(a.substring(len2,len1),b);
    }
    else{
        return compare(a,b.substring(len1,len2));
    }
    
}

function solution(numbers) {
    
    var answer = '';
    for(var i = 0; i < numbers.length; i++){
        numbers[i] = String(numbers[i]);
    }
    numbers.sort(compare);
    numbers.forEach(function(element){
        answer += element;
    })
    var f = true;
    for(var i = 0; i < numbers.length; i++){
        if(numbers[i] != '0'){
            f = false;
        }
    }
    if(f){
        answer = '0';
    }
    return answer;
}