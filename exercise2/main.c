#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    char word[50]; // declare and allocate memory for a char array to hold a word entered by a user
    char c;        // declare a c variable to make if statements easier to read further down

    printf("Please enter a word to encrypt (CTRL+Z/D to exit): "); // display instructions
    
    // while the input is not EOF (EOF does not equal to 1)
    while (scanf("%49s", word) == 1) {
        // loop through until null terminator is found
        for (int i = 0; word[i] != '\0'; i++) {

            // ensure the character is a letter, and not a number or another symbol/sign
            if (isalpha(word[i])) {
                c = word[i]; // assign the char of word[i] to the c variable

                // if c is in the lower half of the alphabet, shift c up by 13 letters
                if ('A' <= c && 'M' >= c || 'a' <= c && 'm' >= c) {
                    word[i] += 13;
                } else { // c is in the upper half of the alphabet, shift c down by 13 letters
                    word[i] -= 13;
                }
            }
        }

        printf("The entered word encrypted is: %s\n\n", word); // print out the result
        printf("Enter another word to encrypt (CTRL+Z/D to exit): ");
    }

    puts("\nExiting program..."); // display exit message

    return 0;
}
