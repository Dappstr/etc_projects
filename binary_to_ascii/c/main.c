#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int exponent(int val, int exp) {
    int result = 1;
    int base = val;
    for(int i = 1; i <= exp; ++i) {
        result *= base;
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

    if(feof(file)) {
        printf("Nothing in file!\n");
        fclose(file); 
        return 1;
    }

    char current_char = 0;
    int index_for_binary_array = 0;
    bool binary_value[8];

    while((current_char = fgetc(file)) != EOF) {
        reset_binary(binary_value);
        if(current_char == '0' || current_char == '1') {
           binary_value[index_for_binary_array++] = (current_char == '0'); // If current_char is a '0' the index will be true which is 0, otherwise 1 
        }
        else if ((current_char == ' ' || current_char == '\n') && index_for_binary_array == 8) {
            int dec_value = binary_to_decimal(binary_value);
            char letter = (char) dec_value;
            printf("%c", letter);
            reset_binary(binary_value);
            index_for_binary_array = 0;
            continue;
        }
        else if(current_char == ' ' || current_char == '\n') {
            index_for_binary_array = 0;
        }
        else {
            printf("Unexpected char found in file!\n");
            fclose(file);
            return 1;
        }
    }
    fflush(stdout);
    return 0;
}

