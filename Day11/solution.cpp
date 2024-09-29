class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int cnt=1;
        int maxi=height[0];
        int n=height.size();
        
        for(int i=1;i<n;i++){
            if(height[i]>maxi){
                cnt++;
                maxi=max(maxi,height[i]);
            }
        }
        
        return cnt;
    }
};