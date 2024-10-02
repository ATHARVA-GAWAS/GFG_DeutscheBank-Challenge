class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
     void inorderTraversal(Node* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, result);
        result.push_back(root->data);
        inorderTraversal(root->right, result);
    }
    
    // Function to merge two sorted vectors into one sorted vector.
    vector<int> mergeSortedVectors(vector<int>& list1, vector<int>& list2) {
        vector<int> merged;
        int i = 0, j = 0;
        
        // Merge the two sorted arrays.
        while (i < list1.size() && j < list2.size()) {
            if (list1[i] <= list2[j]) {
                merged.push_back(list1[i]);
                i++;
            } else {
                merged.push_back(list2[j]);
                j++;
            }
        }
        
        // If there are remaining elements in list1, add them.
        while (i < list1.size()) {
            merged.push_back(list1[i]);
            i++;
        }
        
        // If there are remaining elements in list2, add them.
        while (j < list2.size()) {
            merged.push_back(list2[j]);
            j++;
        }
        
        return merged;
    }

    // Function to return a list of integers denoting the node
    // values of both the BSTs in a sorted order.
    vector<int> merge(Node* root1, Node* root2) {
        // Perform inorder traversal on both BSTs.
        vector<int> bst1, bst2;
        inorderTraversal(root1, bst1);
        inorderTraversal(root2, bst2);
        
        // Merge the two sorted vectors and return the result.
        return mergeSortedVectors(bst1, bst2);
    }
};