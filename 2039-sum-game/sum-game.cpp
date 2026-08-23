class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // First half
        for (int i = 0; i < half; i++) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        // Second half
        for (int i = half; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice always wins
        if ((leftQ + rightQ) % 2 == 1) {
            return true;
        }

        // Bob wins only when the difference can be exactly balanced
        if (2 * (leftSum - rightSum) ==
            9 * (rightQ - leftQ)) {
            return false;
        }

        return true;
    }
};