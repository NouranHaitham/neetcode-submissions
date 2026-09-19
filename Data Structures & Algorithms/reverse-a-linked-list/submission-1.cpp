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
    ListNode* reverseList(ListNode* node) {
        if(node == nullptr || node->next == nullptr)
        {  
            return node;  
        }
        ListNode* head = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        return head;
    }
};
