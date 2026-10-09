class Solution {

    private int n, target;
    private List<List<Integer>> result = new ArrayList<>();
    private void solve(int sum,int indx,int[] nums,List<Integer> list)
    {   
        if(sum > target) return;
        if(sum == target)
        {
            List<Integer> ll = new ArrayList(list);
            result.add(ll);
        }

        for(int i=indx;i<n;i++)
        {
            sum += nums[i];
            list.add(nums[i]);
            solve(sum,i,nums,list);
            sum-= nums[i];
            list.remove(Integer.valueOf(nums[i]));
        }
    }

    public List<List<Integer>> combinationSum(int[] nums, int target) {
        
        n = nums.length;
        this.target = target;
        List<Integer> list = new ArrayList<>();
        solve(0,0,nums,list);
        return result;
    }
}
