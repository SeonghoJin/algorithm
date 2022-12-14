use std::io::{self};
use std::cmp::{self};
use std::num::{self};

fn main(){
    let mut buffer = String::new();

    io::stdin().read_line(&mut buffer);
    buffer.pop();

    let first = buffer.parse::<i32>().unwrap();

    buffer.clear();
    io::stdin().read_line(&mut buffer);
    buffer.pop();

    let second = buffer.parse::<i32>().unwrap();

    let mut answer1 = 100001;
    let mut answer2 = 0;

    for i in first..(second + 1) {
        let sqrtnum = f32::sqrt(i as f32).floor();

        if (sqrtnum * sqrtnum) as i32 == i {
            answer1 = cmp::min(answer1, i);
            answer2 += i;
        }
   }

   if answer2 == 0 {
    println!("-1");
    return;
   }

   println!("{answer2}");
   println!("{answer1}");
}