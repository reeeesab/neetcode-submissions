class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            int local_max =1;
            int n= nums[i];
            while(s.find(n-1)!=s.end()){
                local_max++;
                n--;
            }
            maxi=max(maxi, local_max);
        }
        return maxi;
    }
};
