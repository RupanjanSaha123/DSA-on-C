class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // 1. Remove both from front
        int fromFront = max(minIndex, maxIndex) + 1;

        // 2. Remove both from back
        int fromBack = n - min(minIndex, maxIndex);

        // 3. Minimum from front, maximum from back
        int mixed1 = minIndex + 1 + (n - maxIndex);

        // 4. Maximum from front, minimum from back
        int mixed2 = maxIndex + 1 + (n - minIndex);

        return min({fromFront, fromBack, mixed1, mixed2});
    }
};