class Solution {
public:
    int reverseBits(int n) {
        string s;
        int count=0;
        while (n>0){
            if(n%2==0) s+="0";
            else s+="1";
            count++;
            n/=2;
        }
        s += string(32-count,'0');
        // reverse(s.begin(),s.end());

        long long ans=0;

        for(int i=0;i<32;i++){
            if(s[i]=='1'){
                ans += pow(2,31-i);
            }
        }
        return ans;
    }
};