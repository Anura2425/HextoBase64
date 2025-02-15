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
    // Convert hexstring to decimal array
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

    // TODO: can remove later just for testing
    for (int i = 0; i < size; i++){ 
        printf("%d ", hex_value_array[i]);
    }

    // Decimal to binary conversion
    int binary_size = size * 4; // use 4 here b/c each hex digit is represented by 4 binary digits
    uint8_t* binary_array;
    binary_array = (uint8_t*) malloc(binary_size * sizeof(uint8_t));
    if (binary_array == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    // Convert each hex value to its binary representation
    for (int i = 0; i < size; i++){
        // Each hex digit represents 4 binary digits so use 4 again
        for (int j = 0; j < 4; j++){
            // Shift the hex value right by (3-j) and mask with 1 to get the j-th binary digit
            binary_array[i*4 + j] = (hex_value_array[i] >> (3-j)) & 1;
        }
    }

    // TODO: can remove later just for testing
    printf("\n");
    for (int i = 0; i < binary_size; i++){ 
        printf("%d", binary_array[i]);
    }
    printf("\n");
    
    free(hex_value_array);
    return binary_array;
}

char* binary_to_base64(uint8_t* binary_array, size_t binary_size, const char base64_chars[]){
    // Converts binary array to base64 characters
    size_t output_size = ((binary_size + 2) / 3) * 4; // TODO: +1 for null terminator
    char* b64_string = (char*) malloc(output_size);
    if (b64_string == NULL){
        return NULL;
    }

    uint32_t temp_buffer;
    size_t i, j;
    char* b64_output_pointer = b64_string;

    // pack 24 bits into buffer (3 bytes or 6 hex digits)
    for (i = 0; i < binary_size; i += 3){ 
        temp_buffer = binary_array[i] << 16; // first byte
        if (i + 1 < binary_size){
            temp_buffer |= binary_array[i + 1] << 8; // second byte
        }
        if (i + 2 < binary_size){
            temp_buffer |= binary_array[i + 2]; // third byte
        }
        // now extract the bits in 6 byte chunks
        for (j = 0; j < 4; j++){
            // TODO: write code to extract the bits in 6 byte chunks
        }
    }
    return b64_string;
}

int main(int argc, char *argv[])  
{  
    char *hex_string = "1CE0";
    uint8_t* binary_array = hex_to_binary(hex_string);
    size_t binary_size = strlen(hex_string) * 4;

    char* b64_string = binary_to_base64(binary_array, binary_size, base64_chars);

    printf("%s\n", b64_string);
    
    free(binary_array);
    free(b64_string);
    
    return 0;
}