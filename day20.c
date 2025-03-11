void zeroSumSubarrays() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
 
    int count = 0;
    /* O(n^2) approach: check all subarrays */
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) count++;
        }
    }
    printf("%d\n", count);
}
 