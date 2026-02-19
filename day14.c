#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) {
        printf("Not an Identity Matrix\n");
        return 0;
    }

    int val;
    int is_identity = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (scanf("%d", &val) != 1) val = 0;

            if (i == j) {
                if (val != 1) {
                    is_identity = 0;
                }
            } else {
                if (val != 0) {
                    is_identity = 0;
                }
            }
        }
    }

    if (is_identity)
        printf("Identity Matrix\n");
    else
        printf("Not an Identity Matrix\n");

    return 0;
}
