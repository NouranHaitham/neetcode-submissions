class Solution {
    public int[] twoSum(int[] nums, int target) {

    Map<Integer,List<Integer>> mp = new HashMap<>();

    int indx = 0;
    for(var num: nums)
    {
        if(!mp.containsKey(num))
        {
            List<Integer> list = new LinkedList<>();
            list.add(indx++);
            mp.put(num,list);
        }
        else
        {
            mp.get(num).add(indx++);
        }
    }

    for(var entry:mp.entrySet())
    {
        int x = entry.getKey();
        int y = target - x;
        if(x == y && mp.get(x).size() > 1)
        {
            return new int[] {mp.get(x).get(0),mp.get(x).get(1)};
        }
        if(x != y && mp.containsKey(y))
        {   
            int i = mp.get(x).get(0);
            int j = mp.get(y).get(0);
            return ((i<j)? new int[]{i,j}: new int[]{j,i});
        }
    }

    return new int[]{-1,-1};
        
    }
}
