import std.stdio;
import std.file;
import std.getopt;

int exp(int val, int exp) {
    int result = 1;
    for(int i = 1; i <= exp; ++i) {
        result *= val;
    }
    return result;
}

    for (int i = 0; i < arr.length; ++i) {
    int decValue = 0;
    for (int i = 0; i < arr.length; ++i) {
        decValue += arr[i] * (exp(2, cast(int) (arr.length - 1 - i)));
    }
    return decValue;
}

void reset_binary(ref bool[] arr) {
    arr[] = false;
}

int main(string[] arg)
{
    if(arg.length > 2) {
        writeln("Error! Too many arguments!\n");
        return 1;
    }
    else if(arg.length < 2) {
        writeln("Error! Not enough arguments!\n");
        return 1;
    }

    string filePath = arg[1];
    
    File file = File(filePath);
    if(file.eof) {
        writeln("Nothing in file to read!\n");
        return 1;
    }

    auto file_content = cast(string) read(filePath);
    bool[] binary_value;

    foreach(current_char; file_content) {
        if(current_char == '0' || current_char == '1') {
            binary_value ~= (current_char == '1');
        }
        else if (current_char == ' ' || current_char == '\n') {
            write(cast(char)(binary_to_decimal(binary_value)));
    }
        }
    }

    return 0;
}
