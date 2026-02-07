/*
//Delete an Element from an Array
#include<stdio.h>
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

//Best Time to Buy and Sell Stock
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    int min_price=arr[0];
    int max_profit=0;
    for (int i=1; i<n; i++) {
        if (arr[i]<min_price) {
            min_price=arr[i];
        } 
        else if (arr[i]-min_price>max_profit) {
            max_profit=arr[i]-min_price;
        }
    }
    printf("Max Profit: %d\n", max_profit);
    return 0;
}
