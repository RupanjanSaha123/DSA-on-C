class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // best[i] = shortest target-sum subarray
        // ending at or before index i
        vector<int> best(n, INT_MAX);

        int left = 0;
        long long sum = 0;
        int ans = INT_MAX;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            // Shrink window if sum becomes greater than target
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Current window has sum = target
            if (sum == target) {
                int len = right - left + 1;

                // Is there a non-overlapping subarray before this one?
                if (left > 0 && best[left - 1] != INT_MAX) {
                    ans = min(ans, len + best[left - 1]);
                }

                // Best single subarray seen so far
                minLen = min(minLen, len);
            }

            // Carry forward the best answer
            if (right == 0)
                best[right] = minLen;
            else
                best[right] = min(best[right - 1], minLen);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};