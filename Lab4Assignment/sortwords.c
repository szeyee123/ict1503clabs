#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LEN 32

struct word_node {
    char word[MAX_WORD_LEN + 1];  // +1 for null terminator
    struct word_node *next;       // Pointer to next node
};
typedef struct word_node WORD_NODE;
typedef WORD_NODE *WORD_NODE_PTR;

// Function to ensure word meets the criteria
int is_valid_word(char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        input[i] = tolower(input[i]);

        // Validate character (lowercase letter, apostrophes, hyphens, or forward slashes)
        if (!islower(input[i]) && input[i] != '\'' && input[i] != '-' && input[i] != '/') {
            return 0;
        }
    }
    return 1;
}

// Function to create a new node
WORD_NODE_PTR create_node(char *word) {
    WORD_NODE_PTR new_node = (WORD_NODE_PTR)malloc(sizeof(WORD_NODE));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    return new_node;
}

// Function to insert the word in alphabetical order
void insert_word(WORD_NODE_PTR *head, char *word) {
    WORD_NODE_PTR new_node = create_node(word);

    // Insert at the front if the list is empty or word is smaller
    if (*head == NULL || strcmp(word, (*head)->word) < 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Find the correct insertion point
    WORD_NODE_PTR current = *head;
    while (current->next != NULL && strcmp(word, current->next->word) > 0) {
        current = current->next;
    }

    // Insert the new node
    new_node->next = current->next;
    current->next = new_node;
}

// Function to print list of words
void print_list(WORD_NODE_PTR head) {
    WORD_NODE_PTR current = head;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }
}

// Function to free allocated memory
void free_list(WORD_NODE_PTR head) {
    WORD_NODE_PTR current = head;
    while (current != NULL) {
        WORD_NODE_PTR temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    char word[MAX_WORD_LEN + 1];
    WORD_NODE_PTR head = NULL;

    while (1) {
        printf("Please enter a word:\n");
        fgets(word, sizeof(word), stdin);

        // Remove trailing newline character if present
        word[strcspn(word, "\n")] = '\0';

        // If enter is entered
        if (strlen(word) == 0) {
            printf("No input detected.\n");
            continue;
        }

        // Program stop
        if (strcmp(word, "***") == 0) {
            break;
        }

        // Validate word
        if (!is_valid_word(word)) {
            printf("The word contains invalid characters.\n");
            continue;
        }

        // Insert word into the list in alphabetical order
        insert_word(&head, word);
    }

    // Print all words in order
    printf("\nAll the entered words in order:\n");
    print_list(head);

    // Free the allocated memory
    free_list(head);

    return 0;
}