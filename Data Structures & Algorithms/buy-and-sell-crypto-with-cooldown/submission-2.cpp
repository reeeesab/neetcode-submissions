#include <cstring>
class Solution {
public:

    int memo[5001][2];

    int dp(vector<int>& prices, int i, int holding) {

        if(i >= prices.size())
            return 0;

        if(memo[i][holding] != -1)
            return memo[i][holding];

        int ans;

        // holding stock
        if(holding) {

            int sell =
                prices[i] + dp(prices, i + 2, 0);

            int skip =
                dp(prices, i + 1, 1);

            ans = max(sell, skip);
        }

        // not holding
        else {

            int buy =
                -prices[i] + dp(prices, i + 1, 1);

            int skip =
                dp(prices, i + 1, 0);

            ans = max(buy, skip);
        }

        return memo[i][holding] = ans;
    }

    int maxProfit(vector<int>& prices) {

        memset(memo, -1, sizeof(memo));

        return dp(prices, 0, 0);
    }
};
