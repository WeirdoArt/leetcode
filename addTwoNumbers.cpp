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

/*
input:
[2,4,3]
[5,6,4]

output:
[7,0,8]
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pHead = new ListNode();
        ListNode* current = pHead;
        ListNode* p = l1, *q = l2;
        int carry = 0;
        while(p || q) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = carry + x + y; // 1[7], 2[10], 3[8]
            carry = sum / 10; // 1[0], 2[1], 3[0]
            current->next = new ListNode(sum % 10); // 1[node->7], 2[node->0], 3[node->8]
            current = current->next;
            
            if(p) p = p->next;
            if(q) q = q->next;
        }
        if(carry > 0) {
            current->next = new ListNode(carry);
        }
        return pHead->next;
    }
};
