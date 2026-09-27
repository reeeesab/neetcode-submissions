class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left=0, right=n-1;
        vector<int> answer(2,0);
        while(right>left){
            int leftNum = numbers[left];
            int rightNum = numbers[right];
            int sum = leftNum + rightNum;
            if(sum>target) right--;
            else if(sum<target) left++;
            else{
                answer[0] = left+1;
                answer[1] = right+1;
                return answer;
            }
        }
        return answer;
    }
};
