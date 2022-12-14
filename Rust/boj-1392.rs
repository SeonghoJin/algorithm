use std::io::{self};
use std::cmp::{self};

fn main(){

    let mut buffer = String::new();

    io::stdin().read_line(&mut buffer);

    let v: Vec<i32> = buffer.split_whitespace().map(|x| x.parse::<i32>().unwrap()).collect();
    let mut arr = [0; 10001];
    let mut current = 0;

    for i in 0..v[0] {
        let mut temp = String::new();
        io::stdin().read_line(&mut temp);
        temp.pop();
        let len = temp.parse::<i32>().unwrap();
        let next = current + cmp::max(0, len);
        for j in current..(next) {
            current+=1;
            arr[j as usize] = i + 1;
        }
    }

    for i in 0..v[1] {
        let mut temp = String::new();
        io::stdin().read_line(&mut temp);
        temp.pop();

        let time = temp.parse::<i32>().unwrap();
        println!("{}", arr[time as usize]);
    }
}