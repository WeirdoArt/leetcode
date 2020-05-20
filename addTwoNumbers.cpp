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
        ListNode *p = l1, *q = l2;
        ListNode head; // 虚拟头节点
        ListNode *currNode = &head;
        int carry = 0;
        while (p || q) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            currNode->next = new ListNode(sum % 10); // 链表操作技巧
            currNode = currNode->next;
            
            p = p ? p->next : p;
            q = q ? q->next : q;
        }
        if (carry > 0) { // 最后检查最高位是否溢出
            currNode->next = new ListNode(carry);
        }
        return head.next; // 返回实际头节点，虚拟头节点在栈上会自动回收
    }
};
/**
解题思路：
    关键点1：除法和求模运算的巧妙应用
    关键点2：链表操作的语法细节（向后迭代）以及虚拟头节点的应用
    遍历两个链表，将两个节点相加得到sum(求和的时候应该把进位考虑进去)，
    把 sum 拆解为“进位”与“个位”（两个个位数相加，进位只能是0或1{9+9+1=19}）    
 */
