class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> pre(52,0);
        for(auto &r:ranges ){
            pre[r[0]]++;
            pre[r[1]+1]-=1;
        }
        int preSum=0;
        for(int i=0;i<=right;i++){
            preSum+=pre[i];
            if(i>=left && preSum==0){
                return false;
            }
        }
        return true;
    }
};