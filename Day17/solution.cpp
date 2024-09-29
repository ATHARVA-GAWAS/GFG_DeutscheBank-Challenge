class Solution {
  public:
  Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // Function to check whether the list is palindrome.
    bool isPalindrome(Node *head) {
        // Your code here
        if (head == nullptr || head->next == nullptr) return true;

        // Step 1: Find the middle of the list using slow and fast pointers
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
    
        // Step 2: Reverse the second half of the list
        Node* secondHalf = reverseList(slow);
        Node* firstHalf = head;
    
        // Step 3: Compare the first half and the reversed second half
        Node* temp = secondHalf;
        while (temp != nullptr) {
            if (firstHalf->data != temp->data) {
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        return true;
    }
};