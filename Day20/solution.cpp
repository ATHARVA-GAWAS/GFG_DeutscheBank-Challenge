class Solution {
  public:
    int f(int ind,int k,vector<int>&arr,vector<int> &dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return 0;
        }
        
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int mini=INT_MAX;
        
        for(int j=1;j<=k;j++){
            if(ind-j>=0){
                int cost=f(ind-j,k,arr,dp)+abs(arr[ind]-arr[ind-j]);
                mini=min(mini,cost);
            }
        }
        
        return dp[ind]= mini;
        
    }
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n=arr.size();
        vector<int> dp(n+1,-1);
        return f(n-1,k,arr,dp);
    }
};