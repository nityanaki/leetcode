// ****BUGGY SOLUTION*****
// passes most test cases, but buggy with nums with 1 digit

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1S = l1;
        ListNode* l2S = l2;
        bool carry = false;
        // is l1 shorter than l2 (for iteration later)
        // bool l1short = false;
        ListNode* longer = l1;
        ListNode* longerS = l1S;
        
        //to save memory, overwrite both the LLs and return the longer one
        while (l1->next && l2->next) {
            int sum = l1->val + l2->val;
            if (carry) {
                sum+=1;
            }
            
            if (sum >= 10) {
                carry = true;
            } else {
                carry = false;
            }
            
            l1->val = sum % 10;
            l2->val = sum % 10;
            
            l1 = l1->next;
            l2 = l2->next;
            
            if (!(l1->next)) {
                longer = l2;
                longerS = l2S;
                break;
            } else if (!(l2->next)) {
                longer = l1;
                longerS = l1S;
                break;
            }
        }
        
        //still need to add this last one
        int sum = l1->val + l2->val;
        if (carry) {
                sum+=1;
        }
        if (sum >= 10) carry = true;
        else carry = false;
        
        longer->val = sum % 10;
        
        if (!(longer->next) && carry) {
            longer->next = new ListNode(1);
            return longerS;
        }
            
        longer = longer->next;
        
        while (longer && longer->next) {
            int sum = longer->val;
            if (carry) {
                sum += 1;
            }
            if (sum >= 10) {
                carry = true;
            } else {
                carry = false;
            }
            longer->val = sum % 10;
            longer = longer->next;
        }
        
        //we should be at the last node now
        if (longer && carry) {
            int sum = longer->val + 1;
            longer->val = sum % 10;
            if (sum >= 10) {
                longer->next = new ListNode(1);
            }
        }
        
        return longerS;
    }
};

// go through linked lists and iterate through length of shorter LL
// add nums at same index
// sum: do mod 10 for number to put in the node, and check if num is > 9 to see if carry is needed
// create new LL node for each sum
// have a carry boolean variable if a one is going to be carried to the next sum
// should just be O(N) time complexity with N being length of longer linked list

// once reached end of shorter LL, then go through rest of longer LL, keeping the carry if the number is 9
// create a new node with 1 as value if hasNext is false and carry is still true

// iteration: recursive or linear?
// linear: go until hasNext is false

// edge cases:
// one LL larger than the other
// LL with 0 value
// LLs with lots of 9s
