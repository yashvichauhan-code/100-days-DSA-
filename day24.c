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

struct Node* insertTail(struct Node *head, int data) {
    struct Node *node = newNode(data);
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
        int x; scanf("%d", &x);
        head = insertTail(head, x);
    }

    int key;
    scanf("%d", &key);

    /* Find and delete first occurrence */
    struct Node *prev = NULL, *cur = head;
    while (cur && cur->data != key) {
        prev = cur;
        cur = cur->next;
    }
    if (cur) {
        if (!prev) head = cur->next;  /* Key is at head */
        else prev->next = cur->next;
        free(cur);
    }

    /* Print result */
    cur = head;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" ");
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