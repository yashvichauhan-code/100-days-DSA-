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

struct Node* mergeSorted(struct Node *l1, struct Node *l2) {
    struct Node dummy;
    dummy.next = NULL;
    struct Node *tail = &dummy;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node *l1 = NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        l1 = insertTail(l1, x);
    }

    int m;
    scanf("%d", &m);
    struct Node *l2 = NULL;
    for (int i = 0; i < m; i++) {
        int x; scanf("%d", &x);
        l2 = insertTail(l2, x);
    }

    struct Node *merged = mergeSorted(l1, l2);

    struct Node *cur = merged;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" ");
        cur = cur->next;
    }
    printf("\n");

    /* Free memory */
    while (merged) {
        struct Node *tmp = merged;
        merged = merged->next;
        free(tmp);
    }
    return 0;
}