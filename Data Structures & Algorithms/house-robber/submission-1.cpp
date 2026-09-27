class Solution {
public:
    int dp(vector<int> &nums,int i, vector<int> &vis){
        if(i>=nums.size()) return 0;
        if(vis[i]!=-1) return vis[i];
        int pick = nums[i] + dp(nums, i+2, vis);
        int dontPick = dp(nums, i+1, vis);
        return vis[i] = max(pick,dontPick);
        return vis[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> vis(101, -1);
        return max(dp(nums, 0, vis), dp(nums, 1, vis));
    }
};
