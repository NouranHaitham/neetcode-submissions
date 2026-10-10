class Solution {
    public int maxSubArray(int[] nums) {
        
        int ans = 0;
        int mx = 0;
        int n = nums.length;
        int mx_ele = nums[0];
        for(int i=0;i<n;i++)
        {
            mx += nums[i];
            if(mx < 0) mx = 0;
            ans = Math.max(ans,mx);
            mx_ele = Math.max(mx_ele,nums[i]);
        }

        if(ans == 0) return mx_ele;
        return ans;

    }
}
