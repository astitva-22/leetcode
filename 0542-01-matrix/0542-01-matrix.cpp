class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1}; 
        vector<vector<int>> ans(n,vector<int>(m,-1));
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dis=q.front().second;
            q.pop();

            ans[r][c]=dis;

            for(int i=0;i<4;i++){
                int nrow = r+dr[i];
                int ncol = c+dc[i];

                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
            
        }
        return ans;
    }
};