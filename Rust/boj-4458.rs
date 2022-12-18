use std::io::{*};

fn main(){
    let mut buffer = String::new();

    let reader = stdin();

    reader.read_line(&mut buffer);

    buffer.pop();

    let mut N = buffer.parse::<i32>().unwrap();

    for i in 0..N {
        buffer.clear();

        reader.read_line(&mut buffer);

        let mut str: Vec<char> = buffer.chars().collect();

        let mut c : Vec<char>= str[0].to_uppercase().collect();
        str[0] = c[0];

        for j in 0..str.len() {
            print!("{}", str[j as usize]);
        }
    }
}