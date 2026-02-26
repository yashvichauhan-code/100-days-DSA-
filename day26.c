#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

struct DNode* newDNode(int data) {
    struct DNode *node = (struct DNode*)malloc(sizeof(struct DNode));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

struct DNode* insertTail(struct DNode *head, int data) {
    struct DNode *node = newDNode(data);
    if (!head) return node;
    struct DNode *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    node->prev = cur;
    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    struct DNode *head = NULL;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        head = insertTail(head, x);
    }

    /* Forward traversal */
    struct DNode *cur = head;
    while (cur) {
        printf("%d", cur->data);
        if (cur->next) printf(" ");
        cur = cur->next;
    }
    printf("\n");

    /* Free memory */
    while (head) {
        struct DNode *tmp = head;
        head = head->next;
        free(tmp);
    }
    return 0;
}// day26
