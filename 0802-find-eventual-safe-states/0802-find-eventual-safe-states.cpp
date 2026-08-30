class Solution {
private:
    bool dfs(int ind,vector<vector<int>>& adj,vector<int> &vis, vector<int>& path,vector<int> &check){
        vis[ind]=1;
        path[ind]=1;
        check[ind]=0;
        for(int i : adj[ind]){
            if(!vis[i]) {
                if(dfs(i,adj,vis,path,check)){
                    return true;
                }
            }
            else if(path[i]==1) {
                check[i]=0;
                return true;
            }
        }
        path[ind]=0;
        check[ind]=1;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n);
        vector<int> path(n);
        vector<int> check(n);

        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,graph,vis,path,check);
        } 
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]) ans.push_back(i); 
        }
        return ans;
    }
};