class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum =0;
        int l=0;
        int size=0;
        int count=0;
        for(int r=0;r<k;r++){
            sum+=arr[r];
        }
        if((sum/k)>=threshold) count++;
        for(int i=k;i<arr.size();i++){
            sum +=arr[i];
            sum -=arr[l++];
            if((sum/k)>=threshold) count++;
        }
        return count ;
    }
};