class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suffix = 1;
        int n = nums.size();
        vector<int> suff(n, 0);
        vector<int> ans(n, 0);
        for(int i = n-1; i>=0; i--){
            suff[i] = suffix;
            suffix*=nums[i];
        }

        int prefix = 1;

        for(int i = 0; i<n; i++){

            ans[i]=prefix*suff[i];

            prefix*=nums[i];
        }

        return ans;
        
    }
};
