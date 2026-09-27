class Solution {
public:
    int climb(int n, vector<int> &vis) {
        if(vis[n]!=0) return vis[n];
        if(n == 1) return 1;
        if(n == 2) return 2;
        vis[n] = climb(n-1,vis) + climb(n-2,vis);
        return vis[n];
    }
    int climbStairs(int n) {

        vector<int> vis(46,0);

        return climb(n,vis);
    }
};