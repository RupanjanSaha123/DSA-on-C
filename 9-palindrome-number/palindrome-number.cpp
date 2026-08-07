class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers cannot be palindrome
        if (x < 0)
            return false;

        int original = x;
        long long rev = 0;

        while (x > 0) {

            int digit = x % 10;

            rev = rev * 10 + digit;

            x = x / 10;
        }

        return original == rev;
    }
};