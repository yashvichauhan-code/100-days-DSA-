void reverseArr(int *arr, int l, int r) {
    while (l < r) {
        int tmp = arr[l]; arr[l] = arr[r]; arr[r] = tmp;
        l++; r--;
    }
}
 
void rotateArray() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int k;
    scanf("%d", &k);
 
    k = k % n;
    /* Reverse entire array, then reverse first k, then rest */
    reverseArr(arr, 0, n - 1);
    reverseArr(arr, 0, k - 1);
    reverseArr(arr, k, n - 1);
 
    for (int i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}
 