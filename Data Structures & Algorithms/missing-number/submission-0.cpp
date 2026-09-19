class Solution {

bitset<1002> freq;

public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            freq[nums[i]] = 1;
        }

        for(int i=0;i<=n;i++)
        {
            if(freq[i] == 0) return i;
        }


    }
};
