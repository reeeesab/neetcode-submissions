class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int j = 0;

        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;

            if (m[nums[i]] > 1)
                return true;

            if (i - j + 1 > k) {
                m[nums[j]]--;
                if (m[nums[j]] == 0)
                    m.erase(nums[j]);
                j++;
            }
        }

        return false;
    }
};