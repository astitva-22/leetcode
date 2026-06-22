class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        
        int can1=INT_MIN;
        int can2=INT_MIN;

        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(can1==nums[i]) cnt1++;
            else if(can2==nums[i]) cnt2++;

            else if(cnt1==0) {
                can1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                can2=nums[i];
                cnt2=1;
            }
            else {
                cnt1--;
                cnt2--;
            }

        }
        if(can1==can2) return {can1};
        int add=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(can1==nums[i]){
                add++;
            }
        }
        if(add>n/3) ans.push_back(can1);
        
        add=0;
        for(int i=0;i<n;i++){
            if(can2==nums[i]){
                add++;
            }
        }
        if(add>n/3) ans.push_back(can2);
        
        return ans ;
    }
};