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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }

        // check current node is leafnode or not
        if(root->left==NULL && root->right==NULL){
            return targetSum==root->val;
        }

        // remove current node val from currentSum
        return hasPathSum(root->left,targetSum-root->val) ||
         hasPathSum(root->right,targetSum-root->val);
    }
};