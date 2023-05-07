#include <iostream>
#include <string>
#include <fstream>
#include <array>

using std::string;

int main(int argc, char* argv[])
{
    if(argc > 2) {
        std::cerr << "Error! Too many arguments!\n";
        std::terminate();
    }
    else if(argc < 2) {
        std::cerr << "Error! Too few arguments!\n";
        std::terminate();
    }

    std::ifstream file (argv[1]);
    
    if(!file.is_open()) {
        std::cerr << "Error! Failed to find file!\n";
        std::terminate();
    }

    else if(file.eof()) {
        std::cerr << "Error! Nothing in file!\n";
        std::terminate();
    }
    
    std::array<bool, 8> binary_value;
    char current_char {};
    int indx = 0;
    
    auto exponent = [](int val, int exp) -> int {
        int result = 1;
        for(int i = 1; i <= exp; ++i) {
            result *= val;
        }
        return result;
    };

    auto binary_to_decimal = [&](std::array<bool, 8>& arr) {
        int dec_value = 0;
        for(int i = 0; i < 8; ++i) {
            dec_value += arr[i] * (exponent(2, 7 - i));
        }
        return dec_value;
    };
  
    auto reset_binary = [&](std::array<bool, 8>& arr) -> void {
        for (auto& i : arr) {
            i = 0;
        }
    };

    char c = 0;
    while((file.get(c))) {
        if(c == '0' || c == '1') {
            binary_value[indx] = (c == '1');
            ++indx;
        }
        else if(c == ' ' || c == '\n') {
            if(indx == 8) {
                std::cout << static_cast<char>(binary_to_decimal(binary_value));
                reset_binary(binary_value);
                indx = 0;
            }
        }
    }

    file.close();
    return 0;
}
