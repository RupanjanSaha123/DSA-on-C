#include <stdio.h>

// Function to calculate factorial
long long fact(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fact(n - 1);
}

// Function to calculate nCr = n! / (r! * (n-r)!)
long long nCr(int n, int r) {
    if (r > n) return 0;   // invalid case
    return fact(n) / (fact(r) * fact(n - r));
}

int main() {
    int n, r;
    printf("Enter n and r: ");
    scanf("%d %d", &n, &r);

    printf("nCr(%d, %d) = %lld\n", n, r, nCr(n, r));
    return 0;
}
