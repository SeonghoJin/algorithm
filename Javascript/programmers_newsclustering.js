function solution(str1, str2) {
    var answer = 0;
    
    str1 = str1.toLowerCase();
    str2 = str2.toLowerCase();
    var s1 = [];
    var s2 = [];
    var s1_c = [];
    var s2_c = [];
    for(var i = 0; i < str1.length - 1;i++){
        if(str1[i] >= 'a' && str1[i] <= 'z' && str1[i+1] >= 'a' && str1[i+1] <= 'z'){   
            var temp = str1.substring(i, i+2);
            if(s1_c.hasOwnProperty(temp)){
                temp += s1_c[temp]++;
            }                     
            else{
                s1_c[temp] = 0;
            }
            s1.push(temp);
        }
    }
     for(var i = 0; i < str2.length - 1; i++){
        if(str2[i] >= 'a' && str2[i] <= 'z' && str2[i+1] >= 'a' && str2[i+1] <= 'z'){
            var temp = str2.substring(i, i+2);
            if(s2_c.hasOwnProperty(temp)){
                temp += s2_c[temp]++;
            }                     
            else{
                s2_c[temp] = 0;
            }
            s2.push(temp);
        }
    }
    
    var sset = [...new Set([...s1, ...s2])];
    var k = s1.filter(it => s2.includes(it));
    
   
    var a = sset.length;
    var b = k.length;
    if(a == 0){
        return 65536;
    }
    else{
        return parseInt(b/a*65536);
    }
    return answer;
}