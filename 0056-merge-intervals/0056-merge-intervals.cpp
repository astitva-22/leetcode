class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0];
        int end=intervals[0][1];
        vector<vector<int>> ans;
        int j=1;
        
        while(j<intervals.size() ){
            if(end>=intervals[j][0]) {
                end=max(intervals[j][1],end);
                j++;
            }
            else{
                
                ans.push_back({start,end});
                start=intervals[j][0];
                end=intervals[j][1];
                j++;
            }
        }
        ans.push_back({start,end});
        return ans;
    }
};