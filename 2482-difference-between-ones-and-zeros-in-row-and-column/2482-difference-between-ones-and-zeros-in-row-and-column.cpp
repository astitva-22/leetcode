class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<int> onesi;
        vector<int> zeroesi;
        vector<int> onesj;
        vector<int> zeroesj;

        for(int i=0;i<n;i++){
            int cnt1=0;
            int cnt0=0;
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) cnt0++;
                else cnt1++;
            }
            onesi.push_back(cnt1);
            zeroesi.push_back(cnt0);
        }
        for(int j=0;j<m;j++){
            int cnt1=0;
            int cnt0=0;
            for(int i=0;i<n;i++){
                if(grid[i][j]==0) cnt0++;
                else cnt1++;
            }
            onesj.push_back(cnt1);
            zeroesj.push_back(cnt0);
        }
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = onesi[i]+onesj[j] - zeroesi[i] - zeroesj[j];
            }
        }
        return ans;
    }
};