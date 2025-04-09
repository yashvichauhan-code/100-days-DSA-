#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};

struct Node* newNode(int coeff, int exp) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->coeff = coeff;
    node->exp   = exp;
    node->next  = NULL;
    return node;
}

struct Node* insertTail(struct Node *head, int coeff, int exp) {
    struct Node *node = newNode(coeff, exp);
    if (!head) return node;
    struct Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL;
    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);
        head = insertTail(head, c, e);
    }

    /* Print polynomial */
    struct Node *cur = head;
    int first = 1;
    while (cur) {
        if (!first) printf(" + ");

        if (cur->exp == 0) {
            /* Constant term: just print coefficient */
            printf("%d", cur->coeff);
        } else if (cur->exp == 1) {
            /* Linear term: coeff x */
            printf("%dx", cur->coeff);
        } else {
            /* Higher degree: coeff x^exp */
            printf("%dx^%d", cur->coeff, cur->exp);
        }

        first = 0;
        cur = cur->next;
    }
    printf("\n");

    /* Free memory */
    while (head) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}