class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mp;

        int l=0;
        int maxi=0;
        int sum=0;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            sum +=nums[r];
            while(l<=r && mp[nums[r]]>1){
                sum -=nums[l];
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            maxi=max(maxi,sum);
        }
        return maxi;
    }
};