class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        queue<vector<int>> q;
        vector<vector<int>> ans;
        for(auto ints: intervals) q.push(ints);

        while(!q.empty()){
            vector<int> currInterval = q.front();
            q.pop();
            //no intervals
            if(newInterval[0]==-1){
                ans.push_back(currInterval);
                continue;
            }
            //no overlap
            if(currInterval[1]<newInterval[0]){
                ans.push_back(currInterval);
            }else if(currInterval[0]>newInterval[1]){  // fits right in
                ans.push_back(newInterval);
                ans.push_back(currInterval);
                newInterval[0] = -1;
            }else{
                newInterval[0] = min(newInterval[0], currInterval[0]);
                newInterval[1]= max(newInterval[1], currInterval[1]);
            }
        }

         if(newInterval[0]!=-1){
                ans.push_back(newInterval);
            }

        return ans;
    }
};
