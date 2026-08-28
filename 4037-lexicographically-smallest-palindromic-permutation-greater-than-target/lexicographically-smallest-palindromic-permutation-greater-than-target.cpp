class Solution {
public:

    string makePalindrome(const string& half, char mid) {
        string ans = half;

        if (mid != '\0')
            ans += mid;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;
        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        // Count characters
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        // Check if palindrome is possible
        int odd = 0;
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Build frequency of characters for left half
        int halfLen = n / 2;
        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++)
            halfFreq[i] = freq[i] / 2;

        string tHalf = target.substr(0, halfLen);

        /*
         * First check whether the palindrome whose
         * first half equals target's first half
         * is already greater than target.
         */
        vector<int> cnt = halfFreq;
        string equalHalf;
        bool possible = true;

        for (char c : tHalf) {
            int x = c - 'a';

            if (cnt[x] == 0) {
                possible = false;
                break;
            }

            equalHalf += c;
            cnt[x]--;
        }

        if (possible) {
            string candidate = makePalindrome(equalHalf, mid);

            if (candidate > target)
                return candidate;
        }

        /*
         * Find the smallest left half that is
         * lexicographically greater than target's
         * first half.
         */
        for (int pos = halfLen - 1; pos >= 0; pos--) {

            cnt = halfFreq;
            string prefix;
            bool ok = true;

            // Match target prefix
            for (int i = 0; i < pos; i++) {
                int x = tHalf[i] - 'a';

                if (cnt[x] == 0) {
                    ok = false;
                    break;
                }

                prefix += tHalf[i];
                cnt[x]--;
            }

            if (!ok)
                continue;

            // Put the smallest character > target[pos]
            for (int c = tHalf[pos] - 'a' + 1; c < 26; c++) {

                if (cnt[c] == 0)
                    continue;

                string half = prefix;
                half += char('a' + c);

                cnt[c]--;

                // Fill remaining positions minimally
                for (int x = 0; x < 26; x++) {
                    while (cnt[x] > 0) {
                        half += char('a' + x);
                        cnt[x]--;
                    }
                }

                string candidate = makePalindrome(half, mid);

                if (candidate > target)
                    return candidate;
            }
        }

        return "";
    }
};