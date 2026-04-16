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
    int solve(TreeNode* root,unordered_map<TreeNode*,int> &dp){
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }
       int opt1=root->val;
        if(root->left) opt1+=solve(root->left->left,dp)+solve(root->left->right,dp);
        if(root->right) opt1+=solve(root->right->left,dp)+solve(root->right->right,dp);

        int opt2=solve(root->left,dp)+solve(root->right,dp);

        return dp[root]=max(opt1,opt2);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        int res=solve(root,dp);
        return res; 
    }
};