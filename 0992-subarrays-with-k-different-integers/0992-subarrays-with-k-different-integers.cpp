class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }

    int fun(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int l=0;
        int ans=0;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            ans +=r-l+1;
        }
        return ans;
    }
};