class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int st=intervals[0][0];
        int end = intervals[0][1];
        int j=1;
        int count=0;
        for(j;j<intervals.size();j++){
            if(end>intervals[j][0]){
                end = min(end, intervals[j][1]);
                count++;
            }
            else{
                st=intervals[j][0];
                end=intervals[j][1];
                
            }
           
        }
        return count;
    }
};