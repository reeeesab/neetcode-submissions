class Solution {
public:
    int dp(vector<int> &nums, int target, int i){
        if(target==0 && i>nums.size()-1) return 1;
        if(i>nums.size()-1) return 0;

        int add = dp(nums, target-nums[i], i+1);
        int substract = dp(nums, target+nums[i],i+1);

        return add+substract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums,target, 0);
    }
};
