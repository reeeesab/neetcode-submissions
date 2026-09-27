class Solution {
public:
    int dp(vector<int>&coins, int i, int amount){
        if(amount==0) return 0;
        if(amount < 0 || i >= coins.size()) return 1e9;
        int take = 1 + dp(coins, i, amount - coins[i]);
        int notTake = dp(coins, i+1, amount);
        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        return dp(coins,0, amount)==1e9?-1:dp(coins, 0, amount);
    }
};
