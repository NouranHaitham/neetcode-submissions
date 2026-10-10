class Node{
    int val, key;
    Node next, prev;

    Node(){}
    Node(int val, int key)
    {   
        this.key = key;
        this.val = val;
        next = prev = null;
    }
}

class LRUCache {

    private int capacity, size;
    private HashMap<Integer,Node> node_loc;
    private Node head, tail;

    public void addToList(Node node)
    {
        if(head == null)
        {
            head = tail = node;
        }
        else
        {
            tail.next = node;
            node.prev = tail;
            tail = tail.next;
        }
    }

    public void removeLRU()
    {
        if(head != null)
        {
            head = head.next;
        }
    }

    public void moveToback(Node node)
    {
        if(node == tail) return;
        if(node == head)
        {
            head = node.next;
            tail.next = node;
            node.prev = tail;
            tail = tail.next;
            return;
        }
        node.prev.next = node.next;
        node.next.prev = node.prev;
        addToList(node);
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        size = 0;
        node_loc = new HashMap<>();
        head = tail = null;
    }
    
    public int get(int key) {

        if(node_loc.containsKey(key))
        {
            moveToback(node_loc.get(key));
            return node_loc.get(key).val;
        }
        return -1;
    }
    
    public void put(int key, int value) {
        
        if(node_loc.containsKey(key))
        {
            node_loc.get(key).val = value;
            moveToback(node_loc.get(key));
        }
        else
        {
            Node node = new Node(value,key);
            if(size < capacity) // add
            {
                size++;
                node_loc.put(key,node);
                addToList(node);
                System.out.println(node.val);
            }
            else
            {
                // remove
                node_loc.remove(Integer.valueOf(head.key));
                removeLRU();
                // add
                node_loc.put(key,node);
                addToList(node);
            }
        }
    
    }
}
