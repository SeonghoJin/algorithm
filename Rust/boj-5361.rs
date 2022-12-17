use std::io::{*, self};


fn main(){
    let mut reader = stdin();
    let mut buffer = String::new();
    let lock = stdout().lock();
    let mut out = io::BufWriter::new(lock);

    reader.read_line(&mut buffer);
    buffer.pop();

    let N = buffer.parse::<i32>().unwrap();

    for _ in 0..N {
        buffer.clear();

        reader.read_line(&mut buffer);
        let mut v: Vec<f32> = buffer.split_whitespace().map(|x| x.parse::<f32>().unwrap()).collect();

        let mut answer: f32 = 0.0;

        answer += 350.34 * v[0];
        answer += 230.90 * v[1];
        answer += 190.55 * v[2];
        answer += 125.30 * v[3];
        answer += 180.90 * v[4];

        println!("${:.2}", answer);
        // writeln!(out ,"{.2}", answer);
    }
}