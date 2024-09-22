#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 255
#define MAGIC_WORD "bread"

int main() {
    char sentence[MAX_SENTENCE_LENGTH];
    char word[MAX_SENTENCE_LENGTH];
    int word_length = 0;
    int magic_word = 0;

    printf("Enter a sentence, up to 255 characters: \n");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isalpha(sentence[i])) {
            word[word_length++] = sentence[i];
        }
        
        else if (isspace(sentence[i]) || ispunct(sentence[i])) {
            if (word_length > 0) {
                word[word_length] = '\0';
                printf("%s %d\n", word, word_length);

                if (strcmp(word, MAGIC_WORD) == 0) {
                    magic_word = 1;
                }

                word_length = 0;
            }
        }
    }

    if (word_length > 0) {
        word[word_length] = '\0';
        printf("%s %d\n", word, word_length);

        if (strcmp(word, MAGIC_WORD) == 0) {
            magic_word = 1;
        }
    }

    if (magic_word) {
        printf("You said the magic word!\n");
    }

    return 0;
}
