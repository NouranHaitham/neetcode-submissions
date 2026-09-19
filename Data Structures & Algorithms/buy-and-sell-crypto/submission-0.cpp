class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();

        int mn = prices[0], mx = prices[0];
        int profit = 0;

        for(int i=1;i<n;i++)
        {
            if(prices[i] < mn)
            {
                mn = prices[i];
            }
            else if(prices[i] > mn)
            {
                mx = prices[i];
                profit = max(profit, mx-mn);
            }
        }

        return profit;
    }
};
