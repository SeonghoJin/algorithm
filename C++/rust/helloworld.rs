use std::io;

fn main() {
    let mut input_number = String::new();

    io::stdin().read_line(&mut input_number)
        .expect("Falied to read line");

    let numbers: Vec<&str> = input_number.split_whitespace().collect();
    println!("{}", numbers[0]);
    let number_a = match numbers[0].parse::<i32>() {
        Ok(i) => i,
        Err(_e) => {
            -1
        }
    };
    
    let number_b = match numbers[1].parse::<i32>() {
        Ok(i) => i,
        Err(_e) => {
            -1
        }
    };

    println!("{}", match numbers[0].parse::<i32>() {
        Ok(i) => i,
        Err(_e) => {
            -1
        }
    } + match numbers[1].parse::<i32>(){
        Ok(i) => i,
        Err(_e) => {
            -1
        }
    });
}