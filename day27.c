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

int listLength(struct Node *head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

void freeList(struct Node *head) {
    while (head) {
        struct Node *tmp = head;
        head = head->next;
        free(tmp);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Node *h1 = NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        h1 = insertTail(h1, x);
    }

    int m;
    scanf("%d", &m);
    struct Node *h2 = NULL;
    for (int i = 0; i < m; i++) {
        int x; scanf("%d", &x);
        h2 = insertTail(h2, x);
    }

    /* Equalize lengths then walk together */
    int l1 = listLength(h1), l2 = listLength(h2);
    struct Node *p1 = h1, *p2 = h2;
    while (l1 > l2) { p1 = p1->next; l1--; }
    while (l2 > l1) { p2 = p2->next; l2--; }

    int found = 0;
    while (p1 && p2) {
        if (p1->data == p2->data) {
            printf("%d\n", p1->data);
            found = 1;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    if (!found) printf("No Intersection\n");

    freeList(h1);
    freeList(h2);
    return 0;
}