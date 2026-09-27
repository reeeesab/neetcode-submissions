#include<bits/stdc++.h>
class Solution {
public:
    int dp[101][101];
    bool solve(int i, int j, string &s1, string &s2, string &s3){
        int k = i+j;
        int n = s1.size();
        int m = s2.size();
        int o = s3.size();
        bool result = false;
        if(i>=n && j>=m & k>=o) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s3[k]) result = solve(i+1, j, s1, s2, s3);
        if(result) return  dp[i][j] =  true;
        if(s2[j]==s3[k]) result= solve(i, j+1, s1, s2, s3);
        return dp[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s1, s2, s3);
    }
};
