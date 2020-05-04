function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    var temp = [];
    var cw = 0;
    var count = 0;
    for(var i = 0; i < bridge_length; i++)temp[i] = 0; 
    for(var i = 0; i < truck_weights.length; i++){
        var here = truck_weights[i];
        
        if(cw + here <= weight){
           cw -= temp[0];
           temp.shift();
           cw += here;
            temp.push(here);
            answer++;
        }
        else{
            while(cw+here > weight){
                cw -= temp[0];
                temp.shift();
                temp.push(0);
                answer++;
            }
            temp.pop();
            cw += here
            temp.push(here);
        }
        
       // console.log(temp, answer);
    }
    while(cw != 0){
        answer++;
        cw-=temp[0];
        temp.shift();
    }
    return answer;
}