class Solution {
public:
    struct Node {
        int leftChar, rightChar;
        int prefix, suffix, best, len;

        Node() {
            leftChar = rightChar = -1;
            prefix = suffix = best = len = 0;
        }

        Node(char c) {
            leftChar = rightChar = c - 'a';
            prefix = suffix = best = len = 1;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        // Entire left interval has same character
        if (a.prefix == a.len && a.rightChar == b.leftChar) {
            res.prefix = a.len + b.prefix;
        }

        // Entire right interval has same character
        if (b.suffix == b.len && a.rightChar == b.leftChar) {
            res.suffix = b.len + a.suffix;
        }

        res.best = max(a.best, b.best);

        // A repeating substring can cross the boundary
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }

        return res;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int idx, int l, int r, int pos, char c) {
        if (l == r) {
            seg[idx] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, c);
        else
            update(idx * 2 + 1, mid + 1, r, pos, c);

        seg[idx] = merge(seg[idx * 2], seg[idx * 2 + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        this->s = s;

        int n = s.size();
        int k = queryCharacters.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char c = queryCharacters[i];

            s[pos] = c;

            update(1, 0, n - 1, pos, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};