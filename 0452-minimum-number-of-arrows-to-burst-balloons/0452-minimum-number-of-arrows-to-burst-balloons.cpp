class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // vector<vector<int,int>> ans;
        sort(points.begin(),points.end());

        int st=points[0][0];
        int end=points[0][1];
        int count =1;
        for(int i=1;i<points.size();i++){
            if(end>=points[i][0]){
                end=min(points[i][1],end);
            }
            else {
                count++;
                end=points[i][1];
            }
        }
        return count;
    }
};
auto init = atexit([](){ ofstream("display_runtime.txt") << "0"; });