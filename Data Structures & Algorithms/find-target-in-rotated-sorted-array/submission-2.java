class Solution {
    public int search(int[] nums, int target) {
        
        int n = nums.length;

        int l = 0, r = n-1;
        while(l<=r) 
        {
            int mid = l + (r-l)/2;
            System.out.println(nums[mid]);
            if(nums[mid] == target)
            {
                return mid;
            }
            
            if(nums[mid] >= nums[l]) // left is sorted
            {
                if(target < nums[mid] && target >=nums[l])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else  // right is sorted
            {
                if(target <= nums[r] && target > nums[mid])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }

            }
          
        }

        return -1;

    }
}
