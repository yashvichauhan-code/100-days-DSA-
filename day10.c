//Read a string and check if it is a palindrome using two-pointer comparison.
#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int start = 0;

    scanf("%s", s);

    int end = strlen(s) - 1;

    while(start < end) {
        if(s[start] != s[end]) {
            printf("NO");
            return 0;
        }
        start++;
        end--;
    }

    printf("YES");
    return 0;
}