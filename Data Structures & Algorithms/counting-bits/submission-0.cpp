class Solution {
public:

    int countOnes(int n)
    {
        int cnt_ones = 0;
        while(n != 0)
        {
            n &= (n-1);
            cnt_ones++;
        }
        return cnt_ones;
    }
    vector<int> countBits(int n) {


        vector<int> result(n+1);

        for(int i=0;i<=n;i++)
        {
            result[i] = countOnes(i);
        }

        return result;

    }
};
