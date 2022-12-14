use std::io::{self};

fn main(){

    let mut line = String::new();

    io::stdin().read_line(&mut line);

    let v: Vec<f64> = line.split_whitespace().map(|x| x.parse::<f64>().unwrap()).collect();

    println!("{}", v[0]/v[1]);
}