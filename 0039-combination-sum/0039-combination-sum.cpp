class Solution {
public:
    void solve(int idx,int n,vector<vector<int>>& ans, vector<int>& ds,vector<int>& nums,int target){
        if(idx>=n){
            if(target==0) ans.push_back(ds);
            return;
        }
        if(nums[idx]<=target) {
            ds.push_back(nums[idx]);
            solve(idx,n,ans,ds,nums,target-nums[idx]);
            ds.pop_back();
        }
        
        solve(idx+1,n,ans,ds,nums,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=candidates.size();
        solve(0,n,ans,ds,candidates,target);
        return ans;
    }
};