class Node{

    int val;
    Node next;

    Node(){}
    Node(int val)
    {
        this.val = val;
        next = null;
    }
}

class LinkedList {

    Node head;
    int size;

    public LinkedList() {
        head = new Node(0);
        size = 0;
    }

    public int get(int index) {

        if(index >= size) return -1;
        
        Node temp = head.next;
        while(index != 0)  
        {
            index--;
            temp = temp.next;
        }

        return temp.val;
    }

    Node getNode(int index) {

        Node temp = head.next;
        while(index != 0)  
        {
            index--;
            temp = temp.next;
        }

        return temp;
    }

    public void insertHead(int val) {

        Node node = new Node(val);

        if(head.next == null)
        {
            head.next = node;
        }
        else
        {
            Node formerHead = head.next;
            head.next = node;
            node.next = formerHead;
        }
        size++;
    }

    public void insertTail(int val) {
        
        if(size == 0)
        {
            insertHead(val);
            return;
        }
        Node tailNode = getNode(size-1);
        Node node = new Node(val);
        tailNode.next = node; 
        size++;
    }

    public boolean remove(int index) {
        
        if(index >= size) return false;

        if(index == 0)
        {
            head.next = head.next.next;
        }
        else
        {
            Node prevNode = getNode(index - 1);
            Node currNode = prevNode.next;
            prevNode.next = currNode.next;
        }
        size--;  
        return true;      
    }

    public ArrayList<Integer> getValues() {

        ArrayList<Integer> nums = new ArrayList<>();

        Node temp = head.next;
        while(temp != null)  
        {   
            nums.add(temp.val);
            temp = temp.next;
        }
        return nums;
    }
}
