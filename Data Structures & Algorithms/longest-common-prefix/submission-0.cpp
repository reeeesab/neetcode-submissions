class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        string ans = "";

        int i = 0, j = 0;

        while(i<first.size() && j<last.size()){
            if(first[i]!=last[j]) break;

            ans+=first[i];
            i++;
            j++;
        }



        return ans;
    }
};