function solution(record) {
    var answer = [];
    record = record.map(x => x.split(' '));
    var m = {};
    for(var i = 0; i < record.length; i++){
        if(record[i][0] != 'Leave')
        m[record[i][1]] = record[i][2];    
    }
    for(var i = 0; i < record.length; i++){
        var name = m[record[i][1]];
        
        if(record[i][0] == "Enter"){
            answer.push(name+"님이 들어왔습니다.")
        }
        else if(record[i][0] == "Leave"){
            answer.push(name+"님이 나갔습니다.")
        }
    }
    //console.log(record);
    return answer;
}