use::std::io::{*};

fn main() {
    let mut line = String::new();

    stdin().read_line(&mut line);
    let v: Vec<f64> = line.split_whitespace().map(|x| x.parse::<f64>().unwrap()).collect();

    let D = v[0];
    let H = v[1];
    let W = v[2];

    let mut answer = (D * D)/ (H*H + W * W);
    answer = answer.sqrt();
    println!("{} {}", (H * answer) as i32, (W * answer) as i32);
}
