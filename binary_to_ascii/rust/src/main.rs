use std::io::Read;
use std::fs::File;
use std::env;
use std::io::Result;

fn main() -> Result<()>{
    let args: Vec<String> = env::args().collect();

    if args.len() > 2 {
            println!("Too many arguments!\n");
            std::process::exit(1);
        }
    else if args.len() < 2 {
          println!("Too few arguments!\n");
          std::process::exit(1);
    }

    let file_path = &args[1];
    let mut file = File::open(file_path)?;
    let mut content = String::new();
    
    file.read_to_string(&mut content)?;
    println!("File contents: {}", content);

    Ok(())
}
