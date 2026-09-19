class Solution {
public:
    int getSum(int a, int b) {

        int sum = 0;

        int carry = 0;
        for(int i=0;i<32;i++)
        {
            int bitA = ((a & (1<<i)) != 0)? 1:0; 
            int bitB = ((b & (1<<i)) != 0)? 1:0; 
            
            if(bitA + bitB + carry == 1)
            {
                sum |= (1<<i);
                carry = 0;
            }
            else if(bitA + bitB + carry == 2)
            {
                carry = 1;
            }
            else if(bitA + bitB + carry == 3)
            {
                sum |= (1<<i);
                carry = 1;
            }
        }

        return sum;
        
    }
};
