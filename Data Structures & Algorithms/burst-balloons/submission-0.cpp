#include<bits/stdc++.h>
class Solution {
public:
    int d[303][303];
    int dp(vector<int> &a, int i,int j){
        if(i>j) return 0;
        if(d[i][j]!=-1) return d[i][j];
        int mini = INT_MIN;
        for(int ind =i; ind<=j; ind++){
            int cost = a[i-1]*a[ind]*a[j+1]+
                dp(a, i, ind-1)+dp(a, ind+1, j);
            mini = max(mini, cost);
        }
       return d[i][j] = mini;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        memset(d, -1, sizeof(d));
        return dp(nums, 1, n);
    }
};
