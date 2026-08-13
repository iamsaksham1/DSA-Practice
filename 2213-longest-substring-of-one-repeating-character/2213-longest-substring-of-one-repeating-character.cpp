class Solution {
public:

    struct Node {
        char leftChar, rightChar;
        int len;
        int prefix, suffix, best;

        Node() {
            leftChar = rightChar = '#';
            len = 0;
            prefix = suffix = best = 0;
        }
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Prefix
        res.prefix = a.prefix;

        // Only if the ENTIRE left segment has same character
        if (a.prefix == a.len && a.rightChar == b.leftChar) {
            res.prefix = a.len + b.prefix;
        }

        // Suffix
        res.suffix = b.suffix;

        // Only if the ENTIRE right segment has same character
        if (b.suffix == b.len && a.rightChar == b.leftChar) {
            res.suffix = b.len + a.suffix;
        }

        // Best inside either segment
        res.best = max(a.best, b.best);

        // Join suffix of left + prefix of right
        if (a.rightChar == b.leftChar) {
            res.best = max(res.best, a.suffix + b.prefix);
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int index, char ch) {

        if (l == r) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].len = 1;
            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;

            return;
        }

        int mid = l + (r - l) / 2;

        if (index <= mid) {
            update(node * 2, l, mid, index, ch);
        }
        else {
            update(node * 2 + 1, mid + 1, r, index, ch);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryCharacters.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            s[index] = ch;

            update(1, 0, n - 1, index, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};