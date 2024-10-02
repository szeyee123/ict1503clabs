// 2303631 Tew Sze Yee

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_lowercase(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
}

int is_word(const char *word) {
    if (strlen(word) > 7) {
        return 0;
    } // Check if word length is more than 7
    
    for (int i = 0; word[i] != '\0'; i++) {
        if (!isalpha(word[i])) {
            return 0; // If input includes non letters
        }
    }
    return 1; 
}

void initialize_current_guess(char *word, char *current_guess) {
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        current_guess[i] = '_'; // Fill with underscores
    }
    current_guess[len] = '\0';
}

void display_current_guess(const char *current_guess) {
    printf("Player 2 has so far guessed: %s\n", current_guess);
}

int letter_in_word(char letter, const char *word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            return 1; // Letter is in word
        }
    }
    return 0; // Letter is not in word
}

void reveal_letter_in_word(char letter, const char *word, char *current_guess) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (word[i] == letter) {
            current_guess[i] = letter;
        }
    }
}

int word_guessed(const char *current_guess) {
    for (int i = 0; current_guess[i] != '\0'; i++) {
        if (current_guess[i] == '_') {
            return 0; // Word still contains hidden letters
        }
    }
    return 1; // Word has been guessed
}

int main() {
    char word[7 + 1], current_guess[7 + 1];
    char guess;
    int incorrect_guesses = 0;

    // Player 1 enters a word
    do {
        printf("Player 1, enter a word of no more than 7 letters:\n");
        scanf("%s", word);
        to_lowercase(word);
        if (!is_word(word)) {
            printf("Sorry, the word must contain only English letters.\n");
        }
    } while (!is_word(word));

    int word_len = strlen(word);
    initialize_current_guess(word, current_guess);

    // Player 2 guessing
    while (incorrect_guesses < 7) {
        display_current_guess(current_guess);
        printf("Player 2, you have %d guesses remaining. Enter your next guess:\n", 7 - incorrect_guesses);
        
        scanf(" %c", &guess);
        guess = tolower(guess);

        // Check if letter is in word
        if (letter_in_word(guess, word)) {
            reveal_letter_in_word(guess, word, current_guess);
        } else {
            incorrect_guesses++;
        }

        // Check if the word has been guessed
        if (word_guessed(current_guess)) {
            display_current_guess(current_guess);
            printf("Player 2 wins.");
            return 0;
        }
    }

    // Player 1 wins if Player 2 exceeds max number of incorrect guesses
    display_current_guess(current_guess);
    printf("Player 2 has failed to guess the word %s. Player 1 wins.\n", word);
    return 0;
}
