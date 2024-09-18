// User function Template for C++

class Solution {
  public:
    int maxLength(string s) {
        // code here
        stack<int> st;
        int maxi= 0;


        st.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {

                st.push(i);
            } else {
                st.pop();

                if (!st.empty()) {

                    maxi = max(maxi, i - st.top());
                } else {
                    st.push(i);
                }
            }
        }

        return maxi;
    }
};