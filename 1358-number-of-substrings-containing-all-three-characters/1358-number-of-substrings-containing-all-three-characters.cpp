class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int l=0;
        int count=0;
        for(int r=0;r<s.size();r++){
            if(s[r]=='a') a++;
            if(s[r]=='b') b++;
            if(s[r]=='c') c++;

            while( l<=r && a>0 && b>0 && c>0){
                count += s.size()-r;
                if(s[l]=='a') a--;
                if(s[l]=='b') b--;
                if(s[l]=='c') c--;
                l++;
            }
        }
        return count;
    }
};