#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    
    // Read the size of the array
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    int *arr = (int*)malloc(n * sizeof(int));

    // Read n integers
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 1. Sort the array so identical elements are neighbors
    qsort(arr, n, sizeof(int), compare);

    // 2. Iterate and count frequencies
    for (int i = 0; i < n; i++) {
        int count = 1;

        // Check how many times the current element repeats
        while (i < n - 1 && arr[i] == arr[i + 1]) {
            count++;
            i++;
        }

        // Print in the required format
        printf("%d:%d\n", arr[i], count);
    }

    free(arr);
    return 0;
}

