var cc = 0;
function mergesort(obj, li, ri, callback){
    var mid = (li + ri)/2;
    mid = parseInt(mid);
    if(li == ri)return;
    mergesort(obj,li,mid,callback);
    mergesort(obj,mid+1,ri,callback);
    
    var arr = Array(ri - li + 1);
   
    
    var nli = li;
    var nri = mid+1;
    var idx = 0;
    while(nli <= mid || nri <= ri){
          if(nri > ri || nli <= mid && callback(obj[nli],obj[nri])){
          arr[idx++] = obj[nli++];   
          }
          else{
          arr[idx++] = obj[nri++];
          }
    }
    
    for(var i = 0; i < idx; i++){
        obj[li+i] = arr[i];
    }
}

function compare1(a, b){
    var str1 = a[0].toLowerCase();
    var str2 = b[0].toLowerCase();
    return str1 == str2 ? compare2(a,b) : str1 <= str2;
}

function compare2(a,b){
    
    var t = parseInt(a[1]);
    var c = parseInt(b[1]);
    return t <= c;
}

function solution(files) {
    var answer = [];
    var nfiles = Array(files.length).fill(null).map(() => Array(3));
    var t = 'A';
    for(var i = 0; i < files.length; i++){
        var head = '';
        var number = '';    
        var str = files[i];
        
        var cnt = 0;
        var flag = true;
        for(var j = 0; j < str.length; j++){
            if(str[j] >= '0' && str[j] <= '9'){
                if(flag){
                flag = false;
                cnt++;
                }
                if(cnt == 1){
                    number += str[j];
                }
            }
            else{
                flag = true;
                if(cnt == 0){
                    head += str[j]
                }
                else{
                    nfiles[i][2] = str.substring(j);
                    break;
                }
            }
            
            nfiles[i][0] = head;
            nfiles[i][1] = number;
        }
        
    }
    
    console.log(nfiles)
    mergesort(nfiles,0,nfiles.length-1,compare1);    
    console.log(nfiles);
    
    for(var i = 0; i < nfiles.length; i++){
        var ttt = nfiles[i][0] + nfiles[i][1];
        if(nfiles[i][2] != undefined){
            ttt += nfiles[i][2];
        }
        answer.push(ttt);
    }
    
    return answer;
}