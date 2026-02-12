//Problem: Given integers a and b, compute a^b using recursion without using pow() function.
#include <iostream>
using namespace std;

long long power(int a, int b) {
    // Base case
    if (b == 0)
        return 1;

    // Recursive case
    return a * power(a, b - 1);
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << power(a, b);

    return 0;
}
