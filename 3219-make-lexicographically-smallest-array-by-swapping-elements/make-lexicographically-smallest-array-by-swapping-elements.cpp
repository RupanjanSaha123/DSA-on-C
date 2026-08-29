class Solution {
public:

    vector<int> lexicographicallySmallestArray(
        vector<int>& nums,
        int limit
    ) {

        // Store {value, original index}
        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        // Sort by value
        sort(arr.begin(), arr.end());

        // Answer array
        vector<int> ans(nums.size());

        int i = 0;

        // Process each group
        while (i < arr.size()) {

            int j = i;

            // Find the end of current group
            while (j + 1 < arr.size() &&
                   arr[j + 1].first - arr[j].first <= limit) {
                j++;
            }

            // Store values of this group
            vector<int> values;

            for (int k = i; k <= j; k++) {
                values.push_back(arr[k].first);
            }

            // Store original indices
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(arr[k].second);
            }

            // Smallest index gets smallest value
            sort(indices.begin(), indices.end());

            for (int k = 0; k < values.size(); k++) {
                ans[indices[k]] = values[k];
            }

            // Move to next group
            i = j + 1;
        }

        return ans;
    }
};