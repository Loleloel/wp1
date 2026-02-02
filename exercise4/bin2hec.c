#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define HEXDIGITS "0123456789ABCDEF" // define all hex digits in a string
#define MAX_BIT_SIZE 65

int printHexDigits(char []);
int validateArgs(char []);

int main(int argc, char **argv) {
    char input[MAX_BIT_SIZE]; // size of 65 chars as the last element should be the null terminator '\0'

    if (1 < argc) { // check if there are any arguments passed
        if (strcmp("-h", argv[1]) == 0) { // check if the argument passed is the help flag '-h'
            puts("--------- HELP MENU ---------");
            puts("\nAn argument in binary is required when running this program.");
            puts("Example: ./bin2hec 10110111 should evaluate to B7");
            return 0;
        }

        if (validateArgs(argv[1]) != 0) return 2;

        strcpy(input, argv[1]);
    } else if (isatty(STDIN_FILENO)) { // check if STDIN_FILENO is associated with a terminal. This is to handle the case of nothing piped and no arguments passed.
        puts("Error: Missing input. Run the program with the '-h' flag for more help.");
        return 2;
    } else {
        // if (validateArgs(argv[1]) != 0) return 2;
        fgets(input, MAX_BIT_SIZE, stdin); // ensure at most 64 chars are read
    }

    printHexDigits(input);

    return 0;
}

int printHexDigits(char input[]) {
    int hexIndex; // variable to track the hex indices of each set of 4 bits

    for (int i = 0; i < strlen(input); i += 4) { // increment i with 4, as 4 bits translates well to a hex digit
        hexIndex = 0;

        for (int j = 0; j < 4; j++) { // iterate over a set of 4 bits
            int bit = input[i + j] - '0'; // subtract the ascii code of '0' to get the integer value of each bit
            hexIndex |= (bit << (3 - j)); // bitwise-OR-assigns the bit shifted to the left to increment the index
        }                                 // e.g. (dec 1) 0000 0001 | (dec 4) 0000 0100 evaluates to (dec 5) 0000 0101

        putchar(HEXDIGITS[hexIndex]); // print the hexdigit to the console
    }

    putchar('\n'); // print a newline to the console

    return 0;
}

int validateArgs(char input[]) {
    for (int i = 0; i < strlen(input); i++) {
        // Ensure the input is a valid binary representation of an integer number.
        // Each char must be a digit
        // Each char must be either a '0' or a '1'
        // Each binary string must have a remainder of 0 when divided by 8.
        if (!isdigit(input[i]) || ('0' != input[i] && '1' != input[i]) || strlen(input) % 8 != 0) {
            puts("Error: Invalid input. Run the program with the '-h' flag for more help.");
            return 1;
        }
    }

    return 0;
}
