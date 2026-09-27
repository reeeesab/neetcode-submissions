class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j = 0;
        int sum = 0;
        int minLenght = INT_MAX;

        for(int i = 0; i< nums.size(); i++){
            sum+=nums[i];
            while(sum>=target){
                minLenght = min(minLenght, i-j+1);
                sum-=nums[j];
                j++;
            }
        }

        return minLenght==INT_MAX?0:minLenght;
    }
};