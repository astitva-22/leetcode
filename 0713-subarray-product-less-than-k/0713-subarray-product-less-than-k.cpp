class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans=1;
        int cnt=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            ans *= nums[r];
            while(l<=r && ans>=k){
                ans /= nums[l++];
            }
            cnt += r-l+1;

        }
        return cnt;
    }
};