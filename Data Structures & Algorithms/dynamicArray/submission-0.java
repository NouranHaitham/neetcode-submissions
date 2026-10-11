class DynamicArray {

    int capacity, size;
    int [] arr;

    public DynamicArray(int capacity) {
        this.capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    public int get(int i) {
        return arr[i];
    }

    public void set(int i, int n) {
        arr[i] = n;
    }

    public void pushback(int n) {
    
        if(size < capacity) // there is space
        {
            arr[size] = n;
            size++;
            return;
        }

        this.capacity *=2;
        int[] newArr = new int[capacity];
        for(int i=0;i<size;i++)
        {
            newArr[i] = arr[i];
        }

        newArr[size] = n;
        size++;
        arr = newArr;
    }

    public int popback() {
        size--;
        return arr[size];
    }

    private void resize() {

        this.capacity *=2;
        int[] newArr = new int[capacity];
        for(int i=0;i<size;i++)
        {
            newArr[i] = arr[i];
        }
        arr = newArr;  
    }

    public int getSize() {
        return size;
    }

    public int getCapacity() {
        return capacity;
    }
}
