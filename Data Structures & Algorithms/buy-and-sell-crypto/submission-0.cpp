class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell =1;
        int maxProfit = 0;
        while(sell<prices.size()){
            if(prices[sell]<prices[buy]){
                buy=sell;
                sell=buy+1;
            }else{
                maxProfit=max(maxProfit,prices[sell]-prices[buy]);
                sell++;
            }
        }
        return maxProfit;
    }
};
