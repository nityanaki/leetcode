/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || head->next == nullptr) {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* reverse = nullptr;

        while (fast && fast->next) {
            ListNode* temp = slow->next;
            ListNode* temp2 = fast->next->next;
            slow->next = reverse;
            reverse = slow;
            slow = temp;
            fast = temp2;
                        
        }
        
        if (fast) {
            slow = slow->next;
        } // odd case
        
        while (reverse) {
            if (reverse->val != slow->val) {
                return false;
            }
            reverse = reverse->next;
            slow = slow->next;
        }
        return true;
    }
};
