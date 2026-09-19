class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map<int,int> num_index;
        for(int i=0;i<n;i++)
        {
            num_index[nums[i]] = i;
        }    

        for(int i=0;i<n;i++)
        {
            int num1 = nums[i];
            int num2 = target-num1;

            cout<<i<<" "<<num1<<" "<<num2<<" "<<"\n";

            if(num_index.count(num2) == 1)
            {
                if(i != num_index[num2]) return {i,num_index[num2]};
            }
        }

        return {-1,-1};

    }
};
