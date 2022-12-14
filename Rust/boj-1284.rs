use std::io::{self};

const array: [i32; 10] = [
    4, 2, 3, 3, 3, 3, 3, 3, 3, 3 
];

fn main(){

    loop {
        let mut buffer = String::new();
        stdin().read_line(&mut buffer);

        if buffer.ends_with('\n') || buffer.ends_with('r') {
            buffer.pop();
        }

        let mut num: usize = match buffer.parse::<i32>() {
            Ok(value) => value,
            Err(err) => {
                println!("{err}");
                0
            }
        } as usize;

        if num == 0 {
            break;
        }

        let mut answer = 0;
        while num > 0 {
            answer += array[num % 10];
            answer += 1;
            num /= 10;
        }
        answer += 1;

        println!("{}", answer);
    }
}