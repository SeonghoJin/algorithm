use std::io::{*};


fn a(times: &Vec<i32>) -> i32 {
    let mut ret = 0;
    for i in 0..(times.len()) {
        ret += (times[i] / 30) * 10 + 10;
    }

    return ret;
}

fn b(times: &Vec<i32>) -> i32 {
    let mut ret = 0;
    for i in 0..(times.len()) {
        ret += (times[i] / 60) * 15 + 15;
    }
    return ret;
}

fn main(){
    let mut line = String::new();
    let reader = stdin();

    reader.read_line(&mut line);
    line.pop();

    let n = line.parse::<i32>().unwrap();

    line.clear();

    reader.read_line(&mut line);
    let mut v: Vec<i32> = line.split_ascii_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();

    let aa = a(&v);
    let bb = b(&v);

    if aa == bb {
        println!("Y M {}", aa);
        return;
    }

    if aa > bb {
        println!("M {}", bb);
        return;
    }

    if aa < bb {
        println!("Y {}", aa);
        return;
    }
}   