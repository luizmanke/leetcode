/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct list_node {
    int value;
    struct list_node* next_node;
};

struct list_node* createNode(int value) {
    struct list_node* node_p = (struct list_node*) malloc(sizeof(struct list_node));
    node_p->value = value;
    node_p->next_node = NULL;
    return node_p;
}

struct list_node* createList(int* values, int values_size) {
    struct list_node* list;
    struct list_node* pointer;
    for (int i=0; i<values_size; i++) {
        if (i == 0) {
            list = createNode(values[i]);
            pointer = list;
        } else {
            pointer->next_node = createNode(values[i]);
            pointer = pointer->next_node;
        }
    }
    return list;
}

struct list_node* addTwoNumbers(struct list_node* list_1, struct list_node* list_2) {
    struct list_node* result;
    struct list_node* result_p;
    struct list_node* pointer_1 = list_1;
    struct list_node* pointer_2 = list_2;

    // Init variables
    int value_1, value_2, sum_temp, last_value;
    int residual = 0;
    int sum = 0;
    int i = 0;

    while(1) {

        // Compute
        value_1 = pointer_1->value;
        value_2 = pointer_2->value;
        sum_temp = value_1 + value_2 + residual;
        last_value = sum_temp % 10;
        residual = sum_temp / 10;

        // Add to list
        if (i == 0) {
            result = createNode(last_value);
            result_p = result;
        } else {
            result_p->next_node = createNode(last_value);
            result_p = result_p->next_node;
        }
        i++;

        // Case for break
        if (
            pointer_1->next_node == NULL &&
            pointer_2->next_node == NULL &&
            residual == 0
        ) break;

        // Jump to the next value if not NULL
        if (pointer_1->next_node != NULL) {
            pointer_1 = pointer_1->next_node;
        } else {
            pointer_1->value = 0;
        }
        if (pointer_2->next_node != NULL) {
            pointer_2 = pointer_2->next_node;
        } else {
            pointer_2->value = 0;
        }
    }

    return result;
}

int main() {
    int size_1 = 3;
    int values_1[3] = {2, 4, 3};
    int size_2 = 3;
    int values_2[3] = {5, 6, 4};

    // Create lists
     struct list_node* list_1 = createList(values_1, size_1);
     struct list_node* list_2 = createList(values_2, size_2);

    // Compute sum
    struct list_node* result = addTwoNumbers(list_1, list_2);
    printf("inverted sum: ");
    for (int i=0; i<10; i++) {
        printf("%d, ", result->value);
        if (result->next_node == NULL) break;
        result = result->next_node;
    }

    free(list_1);
    free(list_2);
    free(result);
    return 0;
}
