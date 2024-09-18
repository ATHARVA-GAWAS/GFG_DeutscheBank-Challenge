//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}
    bool isStronglyConnected(vector<vector<int>>& adj, vector<vector<int>>& reverseAdj, int start, vector<bool>& visited) {
        int n = adj.size();
    
        // Step 1: Check if all vertices are reachable from start vertex
        fill(visited.begin(), visited.end(), false);
        dfs(start, adj, visited);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (adj[i].size() > 0 || reverseAdj[i].size() > 0) return false;
        }
    
        // Step 2: Check if all vertices are reachable from start vertex in the reverse graph
        fill(visited.begin(), visited.end(), false);
        dfs(start, reverseAdj, visited);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            if (adj[i].size() > 0 || reverseAdj[i].size() > 0) return false;
        }
    
        return true;
}

  public:
    int isCircle(vector<string> &arr) {
        // code here
        int n = arr.size();
        if (n == 0) return false;
    
        // Graph adjacency lists
        vector<vector<int>> adj(26);      // Adjacency list for normal graph
        vector<vector<int>> reverseAdj(26); // Adjacency list for reverse graph
        vector<int> inDegree(26, 0), outDegree(26, 0);
    
        // Build the graph
        for (string& s : arr) {
            int u = s[0] - 'a';  // Start vertex (first char)
            int v = s.back() - 'a';  // End vertex (last char)
            adj[u].push_back(v);
            reverseAdj[v].push_back(u);
            outDegree[u]++;
            inDegree[v]++;
        }
    
        // Check if in-degree equals out-degree for every vertex
        for (int i = 0; i < 26; i++) {
            if (inDegree[i] != outDegree[i]) return false;
        }
    
        // Check if the graph is strongly connected (on the characters involved)
        vector<bool> visited(26, false);
        for (int i = 0; i < 26; i++) {
            if (outDegree[i] > 0) {
                // Perform DFS from this vertex
                return isStronglyConnected(adj, reverseAdj, i, visited);
            }
        }
    
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
