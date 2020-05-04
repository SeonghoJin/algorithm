function solution(skill, skill_trees) {
    var answer = 0;
    
    var mapping =[];
    for(var i = 0; i < skill.length; i++){
        mapping[skill[i]] = i+1;
    }
    console.log(mapping);
    for(var i = 0; i < skill_trees.length; i++){
        var skill_tree = skill_trees[i];
        
        var next = 0;
        var flag = true;
        console.log("start");
        for(var j = 0; j < skill_tree.length; j++){
            if(mapping[skill_tree[j]] == undefined)continue;
            var c = mapping[skill_tree[j]];
            console.log(skill_tree[j]);
            console.log(c);
            if(next < c && next + 1 == c){
                next = c;
            }
            else{
                flag = false;
            }
        }
        console.log(flag);
        if(flag){
            answer++;
        }
    }
    
    return answer;
}