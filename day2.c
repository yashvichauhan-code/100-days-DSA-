/*#include<stdio.h>
int main(){
    int n,pos;
    printf("enter number of integers:");
    scanf("%d",&n);
    int arr[n];
    printf("enter %d elemnets",n);
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }
    printf("enter position: ");
    scanf("%d",&pos);
    for(int i=0; i<n; i++){
        if (i==pos){
            for(int j=i; j<n; j++){
                arr[j]=arr[j+1];
            }
            n--;
        
        }
    }
     printf("array after deletion: ");
    for (int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_price = arr[0]; // Assume first day is cheapest
    int max_profit = 0;

    for (int i = 1; i < n; i++) {
        // 1. If we found a lower price, update our "buy" day
        if (arr[i] < min_price) {
            min_price = arr[i];
        } 
        // 2. Otherwise, check if selling today gives a better profit
        else if (arr[i] - min_price > max_profit) {
            max_profit = arr[i] - min_price;
        }
    }

    printf("Max Profit: %d\n", max_profit);
    return 0;
}
