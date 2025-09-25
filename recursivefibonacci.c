#include <stdio.h>

// Recursive Fibonacci function
int fib(int n) {
    if (n == 0) return 0;     // base case
    if (n == 1) return 1;     // base case
    return fib(n-1) + fib(n-2); // recursion
}

int main() {
    int n;
    printf("Enter how many terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for(int i=0; i<n; i++) {
        printf("%d ", fib(i));
    }
    printf("\n");
    return 0;
}
