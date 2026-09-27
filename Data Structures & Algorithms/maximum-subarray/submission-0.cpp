class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum =INT_MIN;
        int currSum = 0;
        int left = 0, right =0;
        while(right<nums.size()){
            currSum += nums[right];
            maxSum = max(maxSum, currSum);

            if(currSum<0){
                currSum = 0;
                right = right +1;
                left = right;
            }else{
                right++;
            }
        }
        return maxSum;
    }
};
