class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        int prev=0;
        int maxLength=0;
        for(int i=0;i<s.length();i++){
            maxLength = max(maxLength,mp[s[i]]);
            if(i==maxLength) {
                ans.push_back((maxLength-prev)+1);
                prev =maxLength+1;
                maxLength=0;
            }
        }
        return ans;
    }
};