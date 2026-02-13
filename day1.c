#include<stdio.h>
int main(){
    int n, pos, x;
    int arr[100];
    printf("enter number of elements: ");
    scanf("%d", &n);
    printf("enter %d elements: \n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("enter position to insert (1-based): ");
    scanf("%d", &pos);
    printf("enter element to insert: ");
    scanf("%d", &x);
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    printf("updated array:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

int main() {
    int n, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    printf("Enter target: ");
    scanf("%d", &target);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("Output: [%d, %d]\n", i, j);
                return 0;
            }
        }
    }

    return 0;
}

