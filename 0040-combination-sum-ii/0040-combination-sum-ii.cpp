class Solution {
public:
    void solve(int idx,vector<int>& candidates,vector<vector<int>>& ans,vector<int>& ds,int target){
        
            if(target==0){
                ans.push_back(ds);
                return;
            } 

        
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;

            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            solve(i+1,candidates,ans,ds,target-candidates[i]);
            ds.pop_back();
            // solve(idx+1,candidates,ans,ds,target);
        }
       
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,ans,ds,target);
        // sort(ans.begin(),ans.end());
        return ans;
    }
};