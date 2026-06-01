class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count = 0;

        for(int i=0;i<n;i++){
            int st=i,en=i;

            while(st>=0 && en<n && s[st]==s[en]){
                st--;
                en++;
                count++;
            }
            st=i,en=i+1;
            while(st>=0 && en<n && s[st]==s[en]){
                st--;
                en++;
                count++;
            }

        }
        return count;
    }
};