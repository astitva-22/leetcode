class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        int l=0;
        for(l=0;l<k;l++){
            sum+=cardPoints[l];
        }
        l=l-1;
        int maxi=sum;
        int n=cardPoints.size();
        for(int i=n-1;i>=n-k;i--){
            sum+=cardPoints[i];
            sum-=cardPoints[l--];
            maxi = max(maxi,sum);
            
        }
        return maxi;
    }
};