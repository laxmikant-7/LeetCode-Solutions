/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void build(TreeNode* root,unordered_map<int,vector<int>> &m){
        if(!root) return;
        if(root->left){
            m[root->val].push_back(root->left->val);
            m[root->left->val].push_back(root->val);
        }
        if(root->right){
            m[root->val].push_back(root->right->val);
            m[root->right->val].push_back(root->val);
        }
        build(root->left,m);
        build(root->right,m);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int,vector<int>> m;
        build(root,m);
        vector<bool> vis(501,false);
        queue<int> q;
        q.push(target->val);
        vis[target->val]=true;
        while(!q.empty() && k>0){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int node=q.front();
                q.pop();
                for(auto it:m[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
            k--;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};