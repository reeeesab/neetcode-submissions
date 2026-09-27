class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<int> tempInterval = intervals[0];
        vector<vector<int>> ans;
        for(int i = 1; i <intervals.size(); i++){
            vector<int> currIntervals = intervals[i];
            //no condition
            if(tempInterval[1]<currIntervals[0]){
                ans.push_back(tempInterval);
                tempInterval = currIntervals;
            }else if(tempInterval[1]>=currIntervals[0]){
                tempInterval[0] = min(tempInterval[0], currIntervals[0]);
                tempInterval[1] = max(tempInterval[1], currIntervals[1]);
            }else{
                tempInterval = currIntervals;
                ans.push_back(currIntervals);
            }
        }
        ans.push_back(tempInterval);
        return ans;
    }
};
