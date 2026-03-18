class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
       int cost=0;
       int l=0;
       int maxi=0;
       for(int r=0;r<s.length();r++){
         cost += abs(s[r]-t[r]);
        
         while(l<=r && cost > maxCost){
            cost -= abs(s[l]-t[l]);
            l++;
        }
        maxi = max(maxi,r-l+1);
       } 
       return maxi;
    }
};