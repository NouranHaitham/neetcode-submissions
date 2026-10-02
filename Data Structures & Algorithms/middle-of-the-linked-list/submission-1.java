/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {

        // 1 2 3 4 5 6 7   odd  valid
        //       ^     ^
        
        // 1 2 3 4 5 6    
        //     ^       ^

        // 1 2 3 valid odd
        //   ^ ^
 


        if(head == null || head.next == null) return head;

        ListNode slow = head, fast = head;
        if(fast.next!= null && fast.next.next != null)
            fast = fast.next.next; 
        else return head.next;

        while(true)
        {

            if(slow.next != null)
                slow = slow.next;

            if(fast.next!= null && fast.next.next != null)
                fast = fast.next.next; 
            else if(fast.next != null)
                return slow.next;   
            else 
                return slow;  
        }
        
    }
}