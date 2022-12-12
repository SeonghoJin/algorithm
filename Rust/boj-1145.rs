use std::io;
use std::cmp;

fn main(){
    let mut line = String::new();

    std::io::stdin().read_line(&mut line);

    let numbers: Vec<i32>  = line.split_whitespace().map(|x| x.parse().unwrap()).collect();

    for value in 1..1000000 {
        let mut sum = 0;

        for number in &numbers {
            if value % number == 0 {
                sum+=1;
            }
        }

        if sum >= 3 {
            println!("{}", value);
            break;
        }
    }
}
