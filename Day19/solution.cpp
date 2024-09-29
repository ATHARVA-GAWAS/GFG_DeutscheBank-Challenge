class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // your code here
        deque<int> dq;  // Deque to store indices of array elements
    vector<int> result;  // To store the maximums for each window
    
    // Process the first window of size 'k'
    for (int i = 0; i < k; ++i) {
        // Remove elements from the deque that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);  // Add current element at the back of the deque
    }
    
    // Process the rest of the elements
    for (int i = k; i < arr.size(); ++i) {
        // The element at the front of the deque is the largest for the previous window
        result.push_back(arr[dq.front()]);
        
        // Remove elements not part of this window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove elements from the deque that are smaller than the current element
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        // Add current element at the back of the deque
        dq.push_back(i);
    }
    
    // Add the maximum for the last window
    result.push_back(arr[dq.front()]);
    
    return result;
    }