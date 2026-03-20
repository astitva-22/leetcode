class Solution {
public:
void subset(int i,vector<int>&nums,vector<vector<int>>& ans,vector<int> &ds){
        if(i>=nums.size()) {
            ans.push_back(ds);
            return;
        }
        subset(i+1,nums,ans,ds);
        ds.push_back(nums[i]);
        subset(i+1,nums,ans,ds);
        ds.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subset(0,nums, ans,ds);
        return ans;
    }
    
};