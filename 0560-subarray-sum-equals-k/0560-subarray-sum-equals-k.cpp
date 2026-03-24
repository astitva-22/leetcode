class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int> mp;
        int curr=0;
        for(int i=0;i<n;i++){
            mp[curr]++;
            curr+=nums[i];
            if(mp.find(curr-k)!=mp.end()) count +=mp[curr-k];
        }
        return count;
    }
};