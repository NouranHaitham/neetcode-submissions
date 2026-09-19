class Solution {
public:
    int hammingWeight(uint32_t n) {

        // sol 1

        int cnt_ones = 0;
        for(int i=0;i<32;i++)
        {
            int bit = (1LL<<i);
            if(bit & n) cnt_ones++;
        }

        return cnt_ones;
        // sol 2 using builtin functions

    }
};
