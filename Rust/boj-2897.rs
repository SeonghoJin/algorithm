use std::io::{*};

fn isBuilding(c: char) -> bool {
    return c == '#';
}

fn f(c: char) -> i32 {
    if c == 'X' {
        return 1;
    }

    return 0;
}

fn main(){
    let mut line = String::new();

    stdin().read_line(&mut line);

    let v: Vec<i32> = line.split_whitespace().map(|val| val.parse::<i32>().unwrap()).collect();

    let N = v[0];
    let M = v[1];

    let mut m: Vec<Vec<char>> = vec!();

    for i in 0..N {
        line.clear();

        stdin().read_line(&mut line);

        m.push(
            line.chars().collect()
        );
    }

    let mut answer = [0, 0, 0, 0, 0];

    for i in 0..N-1 {
        
        for j in 0..M-1 {
            let a = i as usize;
            let b = j as usize;
            if isBuilding(m[a][b]) 
            || isBuilding(m[a][b + 1])
            || isBuilding(m[a + 1][b])
            || isBuilding(m[a + 1][b + 1]) {
                continue;
            }

            let mut temp = 0;

            temp += 
            f(m[a][b]) + 
            f(m[a][b + 1]) + 
            f(m[a + 1][b]) +
            f(m[a + 1][b + 1]); 

            answer[temp as usize]+=1;
        }

    }

    for i in 0..answer.len(){
        println!("{}", answer[i]);
    }
}