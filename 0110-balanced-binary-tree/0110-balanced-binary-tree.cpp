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
    
     int findHeight(TreeNode* p){
        if(p==NULL){
            return 0;
        }
        return 1+max(findHeight(p->left),findHeight(p->right));
     }
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int l=findHeight(root->left);
        int r=findHeight(root->right);
        if(abs(l-r)>1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};