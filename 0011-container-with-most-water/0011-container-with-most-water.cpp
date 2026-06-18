class Solution {
public:
    int maxArea(vector<int>& height) {
        int st =0 ;
        int en =height.size()-1;

        int maxi=0;
        while(st<en){
            int temp = (en-st)*(min(height[st],height[en]));
            maxi=max(maxi,temp);

            if(height[st]<height[en]) st++;
            else en--;
        }
        return maxi;
    }
};