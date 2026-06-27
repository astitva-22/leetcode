class Solution {
public:
    string longestPalindrome(string s) {
        string res="";

        for(int i=0;i<s.size();i++){
            int st=i,en=i;
            
            while(st>=0 && en<s.size() && s[st]==s[en]){
                st--;
                en++;
            }
            string temp=s.substr(st+1,en-st-1);
            if(temp.size()>res.size()) res=temp;

            st=i;
            en=i+1;
            while(st>=0 && en<s.size() && s[st]==s[en]){
                st--;
                en++;
            }
            temp=s.substr(st+1,en-st-1);
            if(temp.size()>res.size()) res=temp;
        }

        return res;
    }
};