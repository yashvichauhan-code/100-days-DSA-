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
}