use std::io::{self, *};
use std::collections::VecDeque;

fn main() {
    let mut N: i32;
    let mut M: i32;
    let mut R: i32;
    let mut line = String::new();
    let stdout = stdout();
    let mut lock = stdout.lock();
    let mut out = io::BufWriter::new(lock);
    
    std::io::stdin().read_line(&mut line);

    let v: Vec<i32> = line.split_whitespace().map(|x| x.parse().unwrap()).collect();

    N = v[0];
    M = v[1];
    R = v[2];

    let mut deq: VecDeque<i32> = VecDeque::new();
    let mut visited: Vec<i32>  = vec![0; (N + 1) as usize];
    let mut adj = vec![vec!(); (N + 1) as usize];
    let _stdin = stdin();

    for i in 0..M {
        line.clear();
        _stdin.read_line(&mut line);
        let v: Vec<i32> = line
                .split_whitespace()
                .map(|x| x.parse().unwrap())
                .collect();

        adj[v[0] as usize].push(v[1]);
        adj[v[1] as usize].push(v[0]);
    }

    for i in 0..adj.len() {
        adj[i as usize].sort();
        adj[i as usize].reverse();
    }

    deq.push_back(R);
    let mut current = 1;
    visited[R as usize] = current;


    while !deq.is_empty() {
        let cur = deq.pop_front().unwrap();
        for i in 0..adj[cur as usize].len() {
            let mut next = adj[cur as usize][i] as usize;
            if visited[next] == 0 {
                visited[next] = {
                    current += 1;
                    current
                };

                deq.push_back(next as i32);
            }
        }
    }

    for i in 1..=N {
        writeln!(out, "{}", visited[i as usize]).unwrap();
    }
}