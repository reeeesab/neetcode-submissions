#include<bits/stdc++.h>
class Solution {
public:
    int vis[5001][101];
    int dp(vector<int> &coins, int amount, int i){
        if(i>=coins.size()) return 0;
        if(amount < 0) return 0;
        if(vis[amount][i]!=-1) return vis[amount][i];
        if(amount == 0) return 1;
        

        return vis[amount][i] = dp(coins, amount - coins[i], i) + dp(coins, amount, i+1);
        
    }
    int change(int amount, vector<int>& coins) {
        memset(vis, -1, sizeof(vis));
        return dp(coins,amount, 0);
    }
};
