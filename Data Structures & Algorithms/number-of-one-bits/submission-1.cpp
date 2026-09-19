class Solution {
public:
    int hammingWeight(uint32_t n) {

        // sol 2 using builtin functions

        return __builtin_popcount(n);

    }
};
