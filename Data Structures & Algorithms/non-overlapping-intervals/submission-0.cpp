class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt =1;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[1] < b[1];
        });

        int endTime = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            vector<int> interval = intervals[i];

            if(endTime <= interval[0]){
                cnt++;
                endTime = interval[1];
            }
        }


        return intervals.size() - cnt;
    }
};
