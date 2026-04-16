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
    bool isLeaf(TreeNode* root){
        if(root->left==NULL && root->right==NULL) return true;
        else return false;
    }

    void solve(TreeNode* root,vector<vector<int>>& ans,vector<int>& ds,int target){
        if(root==NULL){
            return;
        }
        ds.push_back(root->val);
        if(isLeaf(root) ){
            if(target==root->val) {
                ans.push_back(ds);

            }
        } 
        solve(root->left,ans,ds,target-root->val);
        solve(root->right,ans,ds,target-root->val);
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>ds;

        solve(root,ans,ds,targetSum);
        return ans;
    }
};