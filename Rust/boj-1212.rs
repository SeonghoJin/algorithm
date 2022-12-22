use std::io::{*};
use std::collections::HashMap;

fn main(){
    let stdin = stdin();
    let stdout = stdout();
    
    let mut buffer = String::new();
    stdin().read_line(&mut buffer);

    let mut scores = HashMap::new();

    scores.insert('0', "000");
    scores.insert('1', "001");
    scores.insert('2', "010");
    scores.insert('3', "011");
    scores.insert('4', "100");
    scores.insert('5', "101");
    scores.insert('6', "110");
    scores.insert('7', "111");

    let mut answer = String::new();
    buffer.pop();
    buffer.chars().for_each(|c| answer += scores.get(&c).unwrap());

    loop {
        if answer.len() > 1 && answer.chars().nth(0).unwrap() == '0' {
            answer.remove(0);
        } else {
            break;
        }
    }

    println!("{answer}");
}