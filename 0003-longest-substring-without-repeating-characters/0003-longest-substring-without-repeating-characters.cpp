class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int maxi=0;
        int st=0;
        int en=0;
        int n =s.length();
        while(en<n){
            char c=s[en];
            mp[c]++;
            while(mp[c]>1){
                char w=s[st];
                mp[w]--;
                st++;
            }
            maxi=max(maxi,en-st+1);
            en++;
        } 
        return maxi;
    }
};