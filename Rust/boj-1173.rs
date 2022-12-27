use std::io::{*};
use std::cmp::{self};

fn main(){
    let stdin = stdin();
    let mut buffer = String::new();

    stdin.read_line(&mut buffer);

    let mut v: Vec<i32> = buffer.split_whitespace().map(|s| s.parse::<i32>().unwrap()).collect();

    let mut N = v[0];
    let m = v[1];
    let M = v[2];
    let T = v[3];
    let R = v[4];

    let mut answer = 0;

    let mut current = m;

    if current + T > M {
        println!("-1");
        return;
    }

    while current >= m && current <= M && N > 0{
        let next = current + T;

        if next <= M {
            current = next;
            N-=1;
        } else {
            current = (current - R).max(m);
        }
        answer += 1;
    }

    println!("{answer}");
}