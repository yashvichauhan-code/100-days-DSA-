//Problem: A system receives two separate logs of user arrival times from two different servers. 

#include <stdio.h>

int main() {
    int p, q;

    // Read size of first log
    scanf("%d", &p);
    int a[p];

    // Read first sorted log
    for(int i = 0; i < p; i++) {
        scanf("%d", &a[i]);
    }

    // Read size of second log
    scanf("%d", &q);
    int b[q];

    // Read second sorted log
    for(int i = 0; i < q; i++) {
        scanf("%d", &b[i]);
    }

    int i = 0, j = 0;

    // Merge both logs
    while(i < p && j < q) {
        if(a[i] <= b[j]) {
            printf("%d ", a[i]);
            i++;
        } else {
            printf("%d ", b[j]);
            j++;
        }
    }

    // Print remaining elements of first log
    while(i < p) {
        printf("%d ", a[i]);
        i++;
    }

    // Print remaining elements of second log
    while(j < q) {
        printf("%d ", b[j]);
        j++;
    }

    return 0;
}
