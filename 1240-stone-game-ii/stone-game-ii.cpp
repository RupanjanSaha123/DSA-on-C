class Solution {
public:
    int n;
    vector<int> suffix;
    int dp[105][205];

    int solve(int i, int M) {

        
        if (i >= n)
            return 0;

        
        if (2 * M >= n - i)
            return suffix[i];

        
        if (dp[i][M] != -1)
            return dp[i][M];

        int best = 0;

        
        for (int X = 1; X <= 2 * M; X++) {

            int nextM = max(M, X);

            int opponent = solve(i + X, nextM);

            int current = suffix[i] - opponent;

            best = max(best, current);
        }

        return dp[i][M] = best;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        suffix.assign(n + 1, 0);

        
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};