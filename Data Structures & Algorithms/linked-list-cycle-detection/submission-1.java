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
    public boolean hasCycle(ListNode head) {

        if(head == null) return false;

        // slow and fast pointer
        ListNode slow = head, fast = head;
        while(true)
        {
            // move
            if(slow.next != null) 
                slow = slow.next; // 3
            else return false;

            if(fast.next != null && fast.next.next != null)
                fast = fast.next.next; // 2
            else return false;

            if(fast.equals(slow)) return true;
        }

    }
}
