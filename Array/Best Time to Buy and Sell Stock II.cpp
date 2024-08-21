class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int currprofit =0;
        int price = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            price = min(price , prices[i]);
            currprofit = max(currprofit , prices[i] - price);

            if(currprofit > 0)
            {
                maxprofit +=currprofit;
                price = prices[i];
                currprofit = 0;
            }
        }
        return maxprofit;
    }
};