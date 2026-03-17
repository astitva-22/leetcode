class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum=0;
        int l=0;
        int count=0;
        
        for(int i = 0; i < minutes; i++) {
            if(grumpy[i] == 1)
                count += customers[i];
        }
        int maxi=count;
        for(int r=minutes;r<grumpy.size();r++){
            if(grumpy[r]==1) count +=customers[r];
            if(grumpy[r-minutes]==1) count -=customers[r-minutes];
            maxi=max(count,maxi);
        }
        for(int i=0;i<grumpy.size();i++){
            if(grumpy[i]==0) maxi+=customers[i];
        }
        return maxi;
    }
};