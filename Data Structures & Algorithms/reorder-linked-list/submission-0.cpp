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

private:
   pair<ListNode*,ListNode*> reorderListHelper(ListNode* node,ListNode* origHead) {
        
        // base case
        if(node == nullptr || node->next == nullptr) 
        {
            // return head and tail of list
            return make_pair(origHead,node);
        }

        pair<ListNode*,ListNode*> pp = 
        reorderListHelper(node->next,origHead);
        
        
        // transition
        ListNode* head = pp.first, *tail = pp.second;

        if(head == tail)  return pp;
        
        ListNode* newHead = head->next;
        ListNode* newTail = node;

        if(newTail->next == newHead)  return make_pair(head,head);

        head->next = tail;
        tail->next = newHead;

        head = newHead;
        tail = node;
        node->next = nullptr;

        return make_pair(head,tail);
   }

public:
    void reorderList(ListNode* head) {
        reorderListHelper(head,head);
    }
};
