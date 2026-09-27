class Solution {
public:
    int dp(vector<int>& cost,int i, vector<int> &vis){
        if(vis[i]!=-1) return vis[i];
        int n = cost.size();
        if(n-i==1) return cost[i];
        if(n-i==2) return cost[i];
        int minCost = min(dp(cost,i+1, vis)+cost[i], dp(cost,i+2,vis)+cost[i]);
        vis[i]= minCost;
        return minCost;
    }   
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> vis(101,-1);
        return min(dp(cost,0,vis), dp(cost,1,vis));
    }
};
