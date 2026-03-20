class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sum1=0;
        int sum2=0;
        int n=reward1.size();
        if(k==0){
            for(int i=0;i<reward2.size();i++){
                sum2+=reward2[i];
            }
            return sum2;
        }
        if(k==n){
            return accumulate(reward1.begin(),reward1.end(),0);
        }

        vector<pair<int,int>> diff(n);
        for(int i=0;i<n;i++){
            diff[i]={reward1[i]-reward2[i],i};
        }
        sort(diff.begin(),diff.end(),[](auto &a, auto &b) {
            return a.first > b.first;
        });

        for(int i=0;i<k;i++){
            sum1 +=reward1[diff[i].second];
        }
        for(int i=k;i<n;i++){
            sum2 +=reward2[diff[i].second];
        }
        return sum1+sum2;
    }
};