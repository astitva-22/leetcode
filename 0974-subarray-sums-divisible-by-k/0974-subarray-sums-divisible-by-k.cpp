class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n =nums.size();
        unordered_map<int,int>mp;

        mp[0]=1;
        int pre=0;
        int ans=0;

        for(int i=0;i<n;i++){
            pre+=nums[i];
            int rem=((pre%k)+k)%k;
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};