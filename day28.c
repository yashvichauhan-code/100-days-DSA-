#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* newNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        struct Node *node = newNode(x);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }
    if (tail) tail->next = head;  /* Make circular */

    /* Traverse: stop when we return to head */
    struct Node *cur = head;
    do {
        printf("%d", cur->data);
        if (cur->next != head) printf(" ");
        cur = cur->next;
    } while (cur != head);
    printf("\n");

    /* Break circle before freeing */
    if (tail) tail->next = NULL;
    while (head) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}