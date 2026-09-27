class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size());
        for(int i=0;i<temperatures.size();i++){
            int t = temperatures[i];

            while(!st.empty() && t>temperatures[st.top()]){
                int idx = st.top();
                st.pop();
                ans[idx] = i-idx;
            }
            st.push(i);
        }

        return ans;
    }
};
