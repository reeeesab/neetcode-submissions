#include<bits/stdc++.h>
class Solution {
public:
    int dp[46];
    int helper(int n) {
        if(n==1 || n==2) return dp[n]=n;
        if(dp[n]!=-1) return dp[n];
        int one = helper(n-1);
        int two = helper(n-2);
        return dp[n] = one+two;
    }
    int climbStairs(int n) {
        memset(dp,-1, sizeof(dp));
        return helper(n);
    }
};
