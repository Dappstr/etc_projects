#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int exponent(int val, int exp) {
    int result = 1;
    for(int i = 1; i <= exp; ++i) {
        result *= val;
    }
    return result;
}

int binary_to_decimal(bool arr[8]) {
    int dec_value = 0;
    for(int i = 0; i < 8; ++i) {
        dec_value += arr[i] * (exponent(2, 7 - i));
        // Same thing as above but using bit shifting
        // dec_value += arr[i] * (1 << (7 - i));
    }
    return dec_value;
}

void reset_binary(bool arr[8]) {
    for(int i = 0; i < 8; ++i) {
        arr[i] = 0;
    }
}

int main(int argc, char* argv[])
{
    if(argc < 2 || argc > 2) {
        printf("Usage: ./binary_to_ascii {file}");
        return 1;
    }
    
    FILE* file = NULL;
    file = fopen(argv[1], "r");

    if(!file) {
        printf("Failed to find file!\n");
        fclose(file);
        return 1;
    }

    else if(feof(file)) {
        printf("Nothing in file!\n");
        fclose(file); 
        return 1;
    }

    char current_char = 0;
    int indx = 0;
    bool binary_value[8];

    while((current_char = fgetc(file)) != EOF) {
        if(current_char == '0' || current_char == '1') {
            binary_value[indx] = (current_char == '1');
            ++indx;
        }
        else if(current_char == ' ' || current_char == '\n') {
            if(indx == 8)
            {
                printf("%c", (char)binary_to_decimal(binary_value));
                reset_binary(binary_value);
                indx = 0;
            }
        }
    }

    fflush(stdout);
    return 0;
}

