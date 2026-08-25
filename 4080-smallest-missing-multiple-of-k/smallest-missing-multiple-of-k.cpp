class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        bool present[101] = {false};

        // Mark numbers that exist in nums
        for (int x : nums) {
            present[x] = true;
        }

        // Check k, 2k, 3k, ...
        for (int multiple = k; ; multiple += k) {
            if (multiple > 100 || !present[multiple]) {
                return multiple;
            }
        }
    }
};