use std::io::{BufReader, BufWriter, Read, Write};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let stdin = std::io::stdin();
    let stdout = std::io::stdout();
    let mut stdin = BufReader::new(stdin.lock());
    let mut stdout = BufWriter::new(stdout.lock());

    let mut s = String::new();
    stdin.read_to_string(&mut s)?;

    // let mut it = s
    //     .split_ascii_whitespace()
    //     .map(|x| x.parse::<usize>().unwrap());
    if s == "0\n" {
        writeln!(stdout, "0")?;
        return Ok(());
    }

    s.pop();
    let mut answer = String::with_capacity(s.len() * 3);
    for c in s.chars() {
        let part = match c {
            '0' => "000",
            '1' => "001",
            '2' => "010",
            '3' => "011",
            '4' => "100",
            '5' => "101",
            '6' => "110",
            _ => "111",
        };
        answer.push_str(part);
    }

    writeln!(stdout, "{}", answer.trim_start_matches('0'))?;

    Ok(())
}