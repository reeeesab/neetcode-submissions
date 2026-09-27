class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n;i++){
            int leftInd = i+1;
            int rightInd = n-1;
            while(rightInd>leftInd){
                int currSum = nums[i] + nums[rightInd] + nums[leftInd];
                if(currSum > 0){
                    rightInd--;
                }else if(currSum < 0){
                    leftInd++;
                }else{
                    vector<int> temp (3,0);
                    temp[0]=nums[i];
temp[1]=nums[leftInd];
temp[2]=nums[rightInd];
                    ans.push_back(temp);
                    leftInd++;
rightInd--;
while(leftInd < rightInd && nums[leftInd] == nums[leftInd - 1]) {
    leftInd++;
}

while(leftInd < rightInd && nums[rightInd] == nums[rightInd + 1]) {
    rightInd--;
}
                }
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};
