//TODO
//Store the decimals in an array, create an array of characters for those decimals

use std::env;
use std::fs::File;
use std::io::Read;
use std::io::Result;

fn exponent(val: i32, exp: i32) -> i32 {
    let mut result: i32 = 1;
    let mut i: i32 = 0;

    while i < exp {
        result *= val;
        i += 1;
    }
    result
}

fn binary_to_decimal(arr: [bool; 8]) -> u8 {
    let mut decimal_value: u8 = 0;
    let mut indx: usize = 0;

    while indx < 8 {
        decimal_value += (arr[indx] as u8) * (exponent(2, 7 - (indx as i32)) as u8);
        indx += 1;
    }
    decimal_value
}

fn reset_binary(arr: &mut [bool; 8]) {
    let mut indx: usize = 0;
    while indx < 8 {
        arr[indx] = false;
        indx += 1;
    }
}

fn main() -> Result<()> {
    let args: Vec<String> = env::args().collect();

    if args.len() > 2 {
        println!("Too many arguments!\n");
        std::process::exit(1);
    } else if args.len() < 2 {
        println!("Too few arguments!\n");
        std::process::exit(1);
    }

    let file_path = &args[1];
    let mut file = File::open(file_path)?;
    let mut content = String::new();
    file.read_to_string(&mut content)?;
    println!("File contents: {}", content);

    let mut bitset: [bool; 8] = [false; 8];
    let mut indx: usize = 0;
    for c in content.chars() {
        match c {
            '0' => {
                bitset[indx] = false;
                indx += 1;
            }
            '1' => {
                bitset[indx] = true;
                indx += 1;
            }
            ' ' | '\n' => {
                if indx == 8 {
                    print!("{}", (binary_to_decimal(bitset) as char));
                    indx = 0;
                    reset_binary(&mut bitset);
                }
            }
            _ => print!("Error char!\n"),
        }
    }

    //println!("Translated: {}", formatted_content);
    Ok(())
}
