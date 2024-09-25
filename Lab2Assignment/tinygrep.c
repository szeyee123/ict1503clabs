// 2303631 Tew Sze Yee

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 35

// Flush stdin
void stdinflush() {
    int c;
    c = getchar();
    while ((c != '\n') && (c != EOF)) {
        c = getchar();
    }
}

// Function for match case-sensitively or insensitively, handle dot and underscore characters
int custom_strncmp(const char* text, const char* pattern, int pattern_len, int case_sensitive) {
    for (int i = 0; i < pattern_len; i++) {
        char text_char = text[i];
        char pattern_char = pattern[i];

        // Convert all to lowercase
        if (!case_sensitive) {
            text_char = tolower(text_char);
            pattern_char = tolower(pattern_char);
        }

        // Handle special characters
        if (pattern_char == '.') {
            continue; // '.' matches any character
        }
        
        else if (pattern_char == '_') {
            if (!isspace(text_char)) {
                return 0; // '_' matches any whitespace
            }
        }
        
        else if (text_char != pattern_char) {
            return 0; // Characters don't match
        }
    }
    return 1; // Match found
}


int main() {
    // Variable declaration
    char text[MAX_TEXT_LENGTH + 1];
    char pattern[MAX_TEXT_LENGTH + 1];
    char case_sensitive;
    int match_position = -1;
    
    printf("Enter a text, up to 35 characters: ");
    fgets(text, MAX_TEXT_LENGTH + 1, stdin);
    text[strcspn(text, "\n")] = '\0';
    stdinflush();

    printf("Enter a pattern, up to 35 characters: ");
    fgets(pattern, MAX_TEXT_LENGTH + 1, stdin);
    pattern[strcspn(pattern, "\n")] = '\0';
    stdinflush();

    printf("Should match be case-sensitive (Y/N)? ");
    scanf(" %c", &case_sensitive);
    stdinflush();

    int text_len = strlen(text);
    int pattern_len = strlen(pattern);

    for (int i = 0; i <= text_len - pattern_len; i++) {
        if (custom_strncmp(&text[i], pattern, pattern_len, case_sensitive == 'Y')) {
            match_position = i;  // Match found, store position
            break; 
        }
    }

    // Output
    if (match_position != -1) {
        printf("Matches at position %d\n", match_position);
    } else {
        printf("No match\n");
    }

    return 0;
}