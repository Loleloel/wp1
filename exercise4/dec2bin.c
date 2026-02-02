#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkSizeOfInput(unsigned long);

int main(int argc, char **argv) {
    if (argc < 2) { // if argc < 2, then no arguments are provided
        puts("Error: No arguments provided. Run the program with the '-h' flag for help.");
    return 0;
    } else if (strcmp(argv[1], "-h") == 0) { // check for the help flag
        puts("Help menu here");
        return 0;
    }

    long num = strtoul(argv[1], NULL, 10); // convert the argument to an unsigned long in base 10

    for (int i = checkSizeOfInput(num) - 1; i >= 0; i--) {
        putchar( (num >> i) & 1 ? '1' : '0' ); // if num shifted i steps to the right and 1 are of equal value
    }                                          // put char '1' to console, else put char '0' to console.
    putchar('\n');

  return 0;
}

int checkSizeOfInput(unsigned long num) {
    if (UCHAR_MAX >= num) { // num is within the size of an unsigned char
        return 8; // returns the size of a char in bits
    } else if (USHRT_MAX >= num) { // num is within the size of an unsigned short
        return 16; // returns the size of a short in bits
    } else if (UINT32_MAX >= num) { // num is within the size of an unsigned int
        return 32; // returns the size of an int in bits
    } else { // num is within the size of an unsigned long
        return 64; // return the size of a long in bits
    } 
}
