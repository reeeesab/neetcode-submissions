class Solution {
public:
    bool dp(vector<int>& nums, int i, vector<int> &vis){
        if(vis[i]!=-1) return vis[i];
        if(i>=nums.size()-1) return true;
        if(nums[i]==0 && i < nums.size()) return false;
        bool ans = false;
        for(int j =0; j<nums[i];j++){
            ans+=dp(nums, i+j+1, vis);
        }
        vis[i]=ans;
        return ans;
    }
    bool canJump(vector<int>& nums) {
        vector<int> vis(1001, -1);
        return dp(nums, 0, vis);
    }
};
