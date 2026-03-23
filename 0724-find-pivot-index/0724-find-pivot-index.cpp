class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> preSum(n,0);
        preSum[0]=nums[0];
        for(int i=1;i<n;i++){
            preSum[i]=preSum[i-1]+nums[i];
        }
        if(preSum[n-1]-preSum[0]==0 ) return 0; 
        
        for(int i=1;i<n;i++){
            if(preSum[i-1] ==preSum[n-1]-preSum[i]) return i;

        }
        if(preSum[n-2]==0) return 0;
        return -1;
        
    }
};