//Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.
#include <stdio.h>

void mirror(char str[], int index) {
    // Base case
    if (str[index] == '\0')
        return;

    // Recursive call
    mirror(str, index + 1);

    // Print while returning (reverse order)
    printf("%c", str[index]);
}

int main() {
    char str[1000];

    scanf("%s", str);

    mirror(str, 0);

    return 0;
}
