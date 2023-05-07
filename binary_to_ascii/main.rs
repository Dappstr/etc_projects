#![allow(unused_imports)]
use std::fs::File;
use std::io;
use std::env;


fn main()
{
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 || args.len() > 2 {
        println!("Error! There should be one argument for file path");
        std::process::exit(1);
    }
    let file = File::open(&args[1]);
    let mut content = String::new();

    
        
}

