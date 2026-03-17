class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int sum =0;
        int l=0,r=0;
        int count=INT_MAX;
        while(r<nums.size()){
            
           sum+=nums[r++];
        //    else if(sum>target) sum-=nums[l++];
           while(l<=r && sum>=target) {
            int curr = r-l+1;
            count =min(count,curr);
            sum-=nums[l++];
           }
           
        }
        
        return count==INT_MAX?0:count-1;
    }
};