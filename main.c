// Gavin McClure-Coleman
// Program to convert Hexadecimal to Base64
#include <stdio.h>   

void hexToBinary(char* hexString){
    size_t i = 0;
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
                printf("0000");
                break;
            case '1':
                printf("0001");
                break;
            case '2':
                printf("0010");
                break;
            case '3':
                printf("0011");
                break;
            case '4':
                printf("0100");
                break;
            case '5':
                printf("0101");
                break;
            case '6':
                printf("0110");
                break;
            case '7':
                printf("0111");
                break;
            case '8':
                printf("1000");
                break;
            case '9':
                printf("1001");
                break;
            case 'A':
            case 'a':
                printf("1010");
                break;
            case 'B':
            case 'b':
                printf("1011");
                break;
            case 'C':
            case 'c':
                printf("1100");
                break;
            case 'D':
            case 'd':
                printf("1101");
                break;
            case 'E':
            case 'e':
                printf("1110");
                break;
            case 'F':
            case 'f':
                printf("1111");
                break;
            default:
                printf("\nHexadecimal character is invalid %c", hexString[i]);
        }
        i++;
    }
}

void main()   
{  
    char hexString[100] = "0x1AC";

    printf("\nBinary string: ");

    hexToBinary(hexString);
}