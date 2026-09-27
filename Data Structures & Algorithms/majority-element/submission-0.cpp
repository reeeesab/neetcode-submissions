class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majVal = nums[0];
        int count = 1;
        for(int i =1; i<nums.size(); i++){
            if(count==0){
                majVal = nums[i];
            }
            if(nums[i]==majVal){
                count++;
            }else{
                count--;
            }
        }


        return majVal;
    }
};