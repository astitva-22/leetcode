class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
            
        
        sort(intervals.begin(),intervals.end());
        int e=intervals[0][1];
        int st=intervals[0][0];
        int i=0;
        for(i=1;i<intervals.size();i++){
            if(e>=intervals[i][0]){
                e=max(intervals[i][1],e);
            }
            else{
                ans.push_back({st,e});
                st=intervals[i][0];
                e=intervals[i][1];
            }
        }
        ans.push_back({st,e});
        return ans;
    }
};