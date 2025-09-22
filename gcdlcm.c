#include <stdio.h>

// Recursive function for GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Recursive function for LCM
int lcm(int a, int b) {
    static int multiple = 0; // static variable to keep track
    multiple += b;
    if (multiple % a == 0 && multiple % b == 0)
        return multiple;
    return lcm(a, b);
}

int main() {
    int num1, num2;

    printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of %d and %d is: %d\n", num1, num2, gcd(num1, num2));
    printf("LCM of %d and %d is: %d\n", num1, num2, lcm(num1, num2));

    return 0;
}
