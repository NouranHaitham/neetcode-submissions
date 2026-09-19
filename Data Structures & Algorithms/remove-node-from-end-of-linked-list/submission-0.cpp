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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            temp = temp->next;
            length++;
        }

        // real order
        n = length-n - 1;

        if(n < 0)
        {
           ListNode* ans = head->next;
           delete head;
           return ans;     

        }


        temp = head;
        while(n--)
        {
            temp = temp->next;
        }

        ListNode* del = temp->next;
        temp->next = del->next;
        delete del;

        return head;
    }
};
