class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        
        int maxi=0;
        int currstep=0;
        
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                currstep++;
                maxi=max(maxi,currstep);
            }
            else{
                currstep=0;
            }
        }
        
        return maxi;
    }
};