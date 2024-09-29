class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stringstream ss(str);
        string word;
        vector<string> tokens;
        
        while(getline(ss,word,'.')){
            tokens.push_back(word);
        }
        string ans="";
        reverse(tokens.begin(),tokens.end());
        for(int i=0;i<tokens.size();i++){
            ans+=tokens[i]+'.';
        }
        ans.pop_back();
        return ans;
    }
};