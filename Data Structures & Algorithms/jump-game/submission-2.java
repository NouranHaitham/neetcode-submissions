class Solution {
    private int[] dp;
    private boolean solve(int indx, int n, int[] nums)
    {
        if(indx >= n) { return false;}
        if(indx == n-1) { dp[indx] = 1;return true;}
        
        if(dp[indx] != -1) return (dp[indx] == 1)? true:false;

        for(int i=1;i<=nums[indx];i++)
        {
            if(solve(indx+i,n,nums)) 
            {   
                dp[indx+i] = 1;
                return true;
            }    
        }
        dp[indx]= 0;
        return false;
    }


    public boolean canJump(int[] nums) {
        int n = nums.length;
        dp = new int[n+1];
        for(int i=0;i<n;i++) dp[i] = -1;
        return solve(0,n,nums);
    }
}
