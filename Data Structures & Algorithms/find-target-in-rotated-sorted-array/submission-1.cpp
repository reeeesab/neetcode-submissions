class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size()-1;

        while(upper>=lower){
            int mid = (upper-lower)/2 + lower;
            if(nums[mid]==target) return mid;

            if(nums[mid]>=nums[lower]){
                if(nums[lower]<=target && nums[mid]>target){
                    upper=mid;
                }else{
                    lower=mid+1;
                }
            }else{
                if(nums[mid]<target && nums[upper]>=target){
                    lower=mid+1;
                }else{
                    upper=mid;
                }
            }
        }

        return -1;
    }
};
