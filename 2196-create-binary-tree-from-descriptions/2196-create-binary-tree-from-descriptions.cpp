/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;
        for(auto &d : descriptions) {
            int parent = d[0];
            int ch = d[1];
            bool isLeft = d[2];
            if(mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);

            if(mp.find(ch) == mp.end())
                mp[ch] = new TreeNode(ch);

            if(isLeft)
                mp[parent]->left = mp[ch];
            else
                mp[parent]->right = mp[ch];

            child.insert(ch);
        }
        for(auto &d : descriptions) {
            if(child.find(d[0]) == child.end())
                return mp[d[0]];
        }
        return NULL;
    }
};