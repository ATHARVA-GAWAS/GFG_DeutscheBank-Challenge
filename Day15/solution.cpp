class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> result(2); // result[0] -> repeating, result[1] -> missing
        
\
        for (int i = 0; i < n; i++) {
            freq[arr[i]]++;
        }
        
        // Step 2: Identify the repeating and missing numbers
        for (int i = 1; i <= n; i++) {
            if (freq[i] == 2) {
                result[0] = i;  // Repeating number
            } else if (freq[i] == 0) {
                result[1] = i;  // Missing number
            }
        }
        
        return result;
        
        
    }
};