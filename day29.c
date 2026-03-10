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

    int k;
    scanf("%d", &k);
    k = k % n;

    if (k == 0) {
        /* No rotation needed */
        struct Node *cur = head;
        while (cur) {
            printf("%d", cur->data);
            if (cur->next) printf(" ");
            cur = cur->next;
        }
        printf("\n");
        while (head) {
            struct Node *tmp = head;
            head = head->next;
            free(tmp);
        }
        return 0;
    }

    /* Step 1: Find tail and connect to head (make circular) */
    struct Node *tail = head;
    while (tail->next) tail = tail->next;
    tail->next = head;  /* Circular */

    /* Step 2: Find (n-k)th node — new tail after rotation */
    int steps = n - k;
    struct Node *newTail = head;
    for (int i = 1; i < steps; i++)
        newTail = newTail->next;

    /* Step 3: New head is one after new tail */
    struct Node *newHead = newTail->next;
    newTail->next = NULL;  /* Break circle */

    /* Print */
    struct Node *cur = newHead;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" ");
        cur = cur->next;
    }
    printf("\n");

    /* Free memory */
    while (newHead) {
        struct Node *tmp = newHead;
        newHead = newHead->next;
        free(tmp);
    }
    return 0;
}// day29
