class Solution {
public:
    int dp(vector<int> &nums, int i, vector<int> &vis){
        if(i>=nums.size()-1) return 0;
        if(vis[i]!=-1) return vis[i];
        int jumpDistance = nums[i];
        int globalMin = 1e9;
        for(int j = 1; j<=jumpDistance; j++){
            int currStep = j + i;
            int currMin =dp(nums, currStep, vis);
            globalMin = min(globalMin, currMin);
        }
        vis[i] = 1 + globalMin;
        return vis[i];

    }
    int jump(vector<int>& nums) {
        vector<int> vis(1001, -1);
        return dp(nums, 0, vis);
    }
};
