// Gavin McClure-Coleman
// Program to convert Hexadecimal to Base64
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Base64 char set
const char base64_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// convert individual hexchar to its integer value 
uint8_t hex_char_to_value(char c){
    if (c >= '0'  && c <= '9') {
        return c - '0';
    }
    else if (c >= 'a' && c <= 'f'){
        return c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F'){
        return c - 'A' + 10;
    } else {
        printf("Invalid Hexadecimal Character:\n");
        printf("%c\n", c);
        exit(EXIT_FAILURE);
    }
    return 0;
}

uint8_t* hex_to_binary(char* hex_string){
    // First convert hexstring to decimal array
    int size = strlen(hex_string);
    int* hex_value_array;
    hex_value_array = (int*) malloc(size * sizeof(int));
    if (hex_value_array == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    for(int i = 0; i < size; i++){
        hex_value_array[i] = hex_char_to_value(hex_string[i]);
    }

    // can remove later just for testing
    for (int i = 0; i < size; i++){ 
        printf("%d ", hex_value_array[i]);
    }

    // Now decimal to binary
    int binary_size = size * 4;
    uint8_t* binary_array;
    binary_array = (uint8_t*) malloc(binary_size * sizeof(uint8_t));
    if (binary_array == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    // Convert each hex value to its binary representation
    for (int i = 0; i < size; i++){
        // Each hex digit represents 4 binary digits
        for (int j = 0; j < 4; j++){
            // Shift the hex value right by (3-j) and mask with 1 to get the j-th binary digit
            binary_array[i*4 + j] = (hex_value_array[i] >> (3-j)) & 1;
        }
    }

    // can remove later just for testing
    printf("\n");
    for (int i = 0; i < binary_size; i++){ 
        printf("%d ", binary_array[i]);
    }

    
    free(hex_value_array);
    return binary_array;
}

int main(int argc, char *argv[])  
{  
    char *hex_string = "1CE0";
    uint8_t* binary_array = hex_to_binary(hex_string);
    if (binary_array != NULL) {
        free(binary_array);
    }
    return 0;
}