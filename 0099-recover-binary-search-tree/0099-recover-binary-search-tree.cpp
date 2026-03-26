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
    void postorder(TreeNode* root,vector<int> &temp){
        if(root==NULL) return;
        postorder(root->left,temp);
        postorder(root->right,temp);
        temp.push_back(root->val);
        return;
    }
    void inorder(TreeNode* root,vector<int> &temp,int &idx){
        if(root==NULL) return;
        inorder(root->left,temp,idx);
        root->val=temp[idx];
        idx++;
        inorder(root->right,temp,idx);
        return;

    }
    void recoverTree(TreeNode* root) {
        vector<int> temp;
        postorder(root,temp);
        sort(temp.begin(),temp.end());
        int idx=0;
        inorder(root,temp,idx);
        return;
    }
};