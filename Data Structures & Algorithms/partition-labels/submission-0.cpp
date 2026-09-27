class Solution {
public:
    vector<int> partitionLabels(string s) {
        set<char> window;
        map<char, int> m;
        int idx = 0;
        int cnt = 0;
        vector<int> ans;
        for(auto ch:s) m[ch]++;
        while(idx<s.size()){
            char ch = s[idx];
            cnt++;
            m[ch]--;
           
            window.insert(ch);
            if(m[ch]==0){
                m.erase(ch);
                window.erase(ch);
            }
            if(window.empty()){
                ans.push_back(cnt);
                cnt=0;
            }
            idx++;
        }
        return ans;
    }
};
