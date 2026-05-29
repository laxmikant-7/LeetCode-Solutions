class Solution {
public:

    struct Node {
        int child[26];
        int bestIdx;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
        }
    };

    vector<Node> trie;

    bool better(vector<string>& wc, int a, int b) {

        if (b == -1)
            return true;

        if (wc[a].size() < wc[b].size())
            return true;

        if (wc[a].size() == wc[b].size())
            return a < b;

        return false;
    }

    void insert(string &s, int idx, vector<string>& wc) {

        int node = 0;

        if (better(wc, idx, trie[node].bestIdx))
            trie[node].bestIdx = idx;

        for (int i = s.size() - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(Node());
            }

            node = trie[node].child[c];

            if (better(wc, idx, trie[node].bestIdx))
                trie[node].bestIdx = idx;
        }
    }

    int search(string &q) {

        int node = 0;

        for (int i = q.size() - 1; i >= 0; i--) {

            int c = q[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie.push_back(Node());

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (string &q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};