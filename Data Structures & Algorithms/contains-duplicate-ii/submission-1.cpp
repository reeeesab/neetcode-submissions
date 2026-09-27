class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        int j = 0;
        for(int i = 0; i<nums.size(); i++){
            if(m.find(nums[i])!=m.end()) return true;
            m[nums[i]]++;
            if(i-j>=k){
                m[nums[j]]--;
                if(m[nums[j]]==0) m.erase(nums[j]);
                j++;
            }
            
        }

        return false;
    }
};