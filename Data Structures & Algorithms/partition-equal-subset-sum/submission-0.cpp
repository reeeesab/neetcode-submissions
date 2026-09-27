class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it: nums) sum+=it;

        if(sum%2!=0) return false;

        return dfs(nums,sum/2,0);
    }

    bool dfs(vector<int> &nums, int target, int i){
        if(i == nums.size()) return target==0;
        if(target<0) return false;
        if(target==0) return true;


        return dfs(nums, target-nums[i], i+1) || dfs(nums,target, i+1);
    }
};
