class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        int size  = nums.size();
        int cnt = 0;
        while(j<size && i<size){
            if(i==j && nums[i]!=val){
                i++;
                j++;
            }else{
                if(nums[i]== val && nums[j]!=val){
                swap(nums[i], nums[j]);
                i++;
                j++;
                cnt++;
            }else{
                if(nums[i]!=val){
                    i++;
                }
                if(nums[j]==val){
                    j++;
                }
            }
            }
            
        }

        return i;
    }
};