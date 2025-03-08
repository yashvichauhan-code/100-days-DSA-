#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmpInt(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmpInt);

    int l = 0, r = n - 1;
    int bestL = l, bestR = r;
    int minSum = INT_MAX;

    while (l < r) {
        int sum = arr[l] + arr[r];
        int absSum = sum < 0 ? -sum : sum;
        if (absSum < minSum) {
            minSum = absSum;
            bestL = l;
            bestR = r;
        }
        if (sum < 0) l++;
        else if (sum > 0) r--;
        else break;
    }

    if (arr[bestL] < arr[bestR])
        printf("%d %d\n", arr[bestL], arr[bestR]);
    else
        printf("%d %d\n", arr[bestR], arr[bestL]);

    return 0;
}