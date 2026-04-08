class Solution {
public:
    long long int solve(int idx,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(idx>=coins.size() or amount<0){
            return INT_MAX;
        }
        if(amount==0) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        long long int opt1=1+solve(idx,coins,amount-coins[idx],dp);
        long long int opt2=solve(idx+1,coins,amount,dp);
        return dp[idx][amount]=min(opt1,opt2);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res=solve(0,coins,amount,dp);
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};