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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // store val, index
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i] != nullptr)  pq.push({lists[i]->val,i});
        }

        ListNode* head = nullptr, *temp = nullptr;
        while(!pq.empty()){

            auto [val, index] = pq.top();
            pq.pop();

            if(temp == nullptr)
                head = temp = lists[index];   
            else
                temp->next = lists[index],
            temp = temp->next;
            
            lists[index] = lists[index]->next; 
            if(lists[index] != nullptr)  pq.push({lists[index]->val,index});
        }

        return head;
    }
};
