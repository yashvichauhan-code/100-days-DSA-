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

    int count = 0;
    struct Node *cur = head;
    while (cur) {
        if (cur->data == key) count++;
        cur = cur->next;
    }
    printf("%d\n", count);

    /* Free memory */
    while (head) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}// day25
