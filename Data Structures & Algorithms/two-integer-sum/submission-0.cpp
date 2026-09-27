class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2,0);
        for(int i=0; i<nums.size();i++){
            int new_target = target - nums[i];
            for(int j= i+1;j<nums.size();j++){
                if(new_target==nums[j]){
                    ans[0]=i;
                    ans[1]=j;
                    return ans;
                }
            }
        }
        return ans;
    }
};
