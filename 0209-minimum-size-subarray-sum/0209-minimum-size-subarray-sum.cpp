class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int sum =0;
        int l=0;
        int count=INT_MAX;
        for(int r=0;r<nums.size();r++){
            sum += nums[r];
            while(l<=r && sum >=target){
                count =min(count,r-l+1);
                sum -= nums[l++];
            }
        }
           
        
        
        return count==INT_MAX?0:count;
    }
};