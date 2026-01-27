#include "main.h"

int main(void) {
    char sentences[NUM_SENTENCES * MAX_STR_LEN]; // buffer with enough memory allocated for 5 strings 30 chars long
    char *rows[NUM_SENTENCES];                   // array of pointers to the strings

    // instruct users what to do
    printf("Please type %d sentences, one at a time\n", NUM_SENTENCES);
    readSentences(rows, sentences); // read sentences from user
    puts("");                       // line break
    printSentences(rows);           // print sentences to user

    return 0;
}

// function to read user input.
// reads the number of sentences defined in the NUM_SENTENCES pre-processor
void readSentences(char *rows[], char buffer[]) {
    int index;
    char *actualPos = buffer; // single pointer to keep track of where each string is

    index = 0;

    while (index < NUM_SENTENCES) { // counter-based iteration
        printf("Enter sentence number %d: ", index + 1); // prompt user for sentence
        fgets(actualPos, MAX_STR_LEN, stdin);            // read user input
        
        // if a sentence is unique, add pointer to rows
        if (checkSentenceIsUnique(rows, actualPos, index)) {
            rows[index] = actualPos;            // add pointer to rows array
            flushInputBuffer(actualPos);        // ensure buffer won't overflow into the next sentence
            actualPos += strlen(actualPos) + 1; // move cursor to the index after the sentence user entered
            index++;                            // increment index
        }
    }
}

// function to clear input buffer if user entered more than the predefined max length of 30
void flushInputBuffer(char *actualPos) {
    if (strchr(actualPos, '\n') == NULL) {
        int c;
        // loop until c == newline or EOF to clear overflowing buffer
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

// check if a user entered a unique sentence
bool checkSentenceIsUnique(char *rows[], char *actualPos, int index) {
    for (int i = 0; i < index; i++) {
        // check if the value of a user's entered string already exist in the rows array
        if (strcmp(actualPos, rows[i]) == 0) {
            puts("The sentence already exist, please try again...");
            return false; // return false if sentence is not unique
        }
    }

    return true; // return true if sentence is unique

}

// function to print sentences to console
void printSentences(char *rows[]) {
    int index;
    char selection;

    while (true) {
        printf("Select a number between 1 and %d to print sentence: ", NUM_SENTENCES);
        scanf(" %c", &selection);

        // get index from chars
        // selection = '1' (ascii 49)
        // index = selection (ascii 49) - '1' (ascii 49) = 0
        // selection = '2' (ascii 50)
        // index = selection (ascii 50) - '1' (ascii 49) = 1
        // and so on
        index = selection - '1';

        // if a number out of range or any other character is entered, break loop to exit program
        if (0 > index || NUM_SENTENCES <= index) {
            break;
        }

        // print the sentence to console
        puts(rows[index]);
    }
}

