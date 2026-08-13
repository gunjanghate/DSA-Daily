class Solution {
public:
    struct Node {
        char lchar;
        char rchar;
        int pref;
        int suf;
        int maxlen;
        int len;
    };

    vector<Node> tree;

    Node merge(Node l, Node r) {
        Node res;
        res.lchar = l.lchar;
        res.rchar = r.rchar;

        res.len = l.len + r.len;

        res.pref = l.pref;
        res.suf = r.suf;

        res.maxlen = max(l.maxlen, r.maxlen);

        if (l.rchar == r.lchar) {
            res.maxlen = max(res.maxlen, l.suf + r.pref);

            if (l.pref == l.len) {
                res.pref = l.len + r.pref;
            }

            if (r.suf == r.len) {
                res.suf = l.suf + r.len;
            }
        }
        return res;
    }

    void build(int node, int l, int r, string& s) {
        if (l == r) { // root node
            tree[node] = {s[l], s[r], 1, 1, 1, 1};

            return;
        }

        int m = (l + r) / 2;

        build(2 * node, l, m, s);
        build(2 * node + 1, m + 1, r, s);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) { // root node
            tree[node] = {c, c, 1, 1, 1, 1};

            return;
        }

        int m = (l + r) / 2;

        if (idx <= m) {
            update(2 * node, l, m, idx, c);
        } else {
            update(2 * node + 1, m + 1, r, idx, c);
        }

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {
        int n = s.size();

        tree.resize(4*n);
        build(1, 0, n-1, s);

        vector<int> ans;

        for(int i = 0; i < queryCharacters.size(); i++){
            update(
            1, 0, n-1, queryIndices[i],queryCharacters[i]);

            ans.push_back(tree[1].maxlen);
        }                             
        return ans;
    }
};