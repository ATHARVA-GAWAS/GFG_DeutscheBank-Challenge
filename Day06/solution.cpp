/* Structure for tree and linked list*/

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


// This function should return head to the DLL
class Solution {
  public:
    Node* prevNode = nullptr;
    Node* head = nullptr;

    Node* bToDLL(Node* root) {
        // code here
        
        if (root == nullptr) {
            return nullptr;
        }
        
         bToDLL(root->left);


        if (prevNode == nullptr) {
            head = root;
        } 
        else {
    
            prevNode->right = root;
            root->left = prevNode;
        }
    

        prevNode = root;

        bToDLL(root->right);
    

        return head;  
    }
};