class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j =0;
        int sum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            maxSum = max(sum, maxSum);
            while(sum<0 && j<nums.size() && j<=i){
                sum-=nums[j];
                j++;
            }  
        }

        return maxSum;
    }
};
