//Linear Search with Comparison Count
#include <stdio.h>
int main() {
    int n, k, i;
    int comparisons=0;
    scanf("%d", &n);

    int arr[n];
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &k);
    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i]==k) {
            printf("found at index %d\n", i);
            printf("comparisons = %d\n", comparisons);
            return 0;
        }
    }
    printf("not found\n");
    printf("comparisons = %d\n", comparisons);

    return 0;
}