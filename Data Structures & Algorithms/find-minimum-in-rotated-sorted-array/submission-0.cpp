class Solution {
public:
    int findMin(vector<int> &nums) {
        int lower = 0;
        int upper = nums.size()-1;

        while(upper>lower){
            int mid = (upper - lower)/2 +  lower;


            if(nums[mid]>nums[upper]){
                lower = mid+1;
            }else{
                upper = mid;
            }

        }

        return nums[lower];
    }
};
