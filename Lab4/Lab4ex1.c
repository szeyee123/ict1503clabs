#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct grade_node {
    char *name;
    double grade;
    struct grade_node *next;
};
typedef struct grade_node GRADE_NODE;
typedef GRADE_NODE *GRADE_NODE_PTR;

GRADE_NODE_PTR create_node(char *name, double grade) {
    GRADE_NODE_PTR new_node = (GRADE_NODE_PTR)malloc(sizeof(GRADE_NODE));
    new_node->name = (char *)malloc(strlen(name) + 1);
    strcpy(new_node->name, name);
    new_node->grade = grade;
    new_node->next = NULL;
    return new_node;
}

void print_list(GRADE_NODE_PTR head) {
    GRADE_NODE_PTR current = head;
    while (current != NULL) {
        printf("Student: %s, Grade: %.1f\n", current->name, current->grade);
        current = current->next;
    }
    printf("\n");
}

int main() {
    GRADE_NODE_PTR head = NULL;

    GRADE_NODE_PTR morpheus = create_node("Morpheus", 85.0);
    head = morpheus;  
    print_list(head);

    GRADE_NODE_PTR trinity = create_node("Trinity", 66.5);
    morpheus->next = trinity;
    print_list(head);

    GRADE_NODE_PTR neo = create_node("Neo", 91.5);

    morpheus->next = neo;
    neo->next = trinity;

    print_list(head);

    free(morpheus->name);
    free(morpheus);
    free(neo->name);
    free(neo);
    free(trinity->name);
    free(trinity);

    return 0;
}
