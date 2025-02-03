// Gavin McClure-Coleman
// Program to convert Hexadecimal to Base64
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>

char* hexToBinary(char* hexString){
    size_t i = 0;
    size_t length = strlen(hexString);
    char *binaryString = (char*) malloc(sizeof(char) * length);
    // Initialize the binaryString to an empty string (so it doesnt print weird symbols)
    binaryString[0] = '\0';
    // check if the string begins with 0X
    if(hexString[1] == 'x' || hexString[1] == 'X'){
        // set the index to two to begin at the actual start of the hex value
        i = 2;
    }
    // iterate through each char in the hexString
    // and convert each char to binary value
    while(hexString[i]){
        switch(hexString[i]){
            case '0':
                strcat(binaryString, "0000");
                break;
            case '1':
                strcat(binaryString, "0001");
                break;
            case '2':
                strcat(binaryString, "0010");
                break;
            case '3':
                strcat(binaryString, "0011");
                break;
            case '4':
                strcat(binaryString, "0100");
                break;
            case '5':
                strcat(binaryString, "0101");
                break;
            case '6':
                strcat(binaryString, "0110");
                break;
            case '7':
                strcat(binaryString, "0111");
                break;
            case '8':
                strcat(binaryString, "1000");
                break;
            case '9':
                strcat(binaryString, "1001");
                break;
            case 'A':
            case 'a':
                strcat(binaryString, "1010");
                break;
            case 'B':
            case 'b':
                strcat(binaryString, "1011");
                break;
            case 'C':
            case 'c':
                strcat(binaryString, "1100");
                break;
            case 'D':
            case 'd':
                strcat(binaryString, "1101");
                break;
            case 'E':
            case 'e':
                strcat(binaryString, "1110");
                break;
            case 'F':
            case 'f':
                strcat(binaryString, "1111");
                break;
            default:
                printf("\nHexadecimal character is invalid %c", hexString[i]);
        }
        i++;
    }
    return binaryString;
    free(binaryString);
}

int main(int argc, char *argv[])  
{  
    char *binaryString;
    char hexString[100] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

    binaryString = hexToBinary(hexString);
    if (binaryString == NULL){
        return -1; // in case allocation fails, return -1 (error)
    }
    printf("\nBinary string: %s", binaryString);
    // free the allocated memory
    free(binaryString);
    return 0;
}