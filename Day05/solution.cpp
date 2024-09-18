// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos,neg;
        
        for(auto it: arr){
            if(it>=0){
                pos.push_back(it);
            }
            else{
                neg.push_back(it);
            }
        }
        
        int i = 0, j = 0;
        int k = 0; 
        
 
        while (i < pos.size() && j < neg.size()) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        

        while (i < pos.size()) {
            arr[k++] = pos[i++];
        }
        

        while (j < neg.size()) {
            arr[k++] = neg[j++];
        }
    }
};