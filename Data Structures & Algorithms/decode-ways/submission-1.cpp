class Solution {
public:
    int dp(string s, int i, vector<int> &vis){
        if(i==s.size()) return 1;
        if(vis[i]!=-1) return vis[i];
        if(s[i]=='0') return 0;

        int ways = dp(s, i+1, vis);

        if(i+1 < s.size()){
            int num = (s[i]-'0')*10+(s[i+1]-'0');
            if(num >= 10 && num <=26){
                ways+=dp(s,i+2, vis);
            }
        }
       return vis[i] =ways;
    }
    int numDecodings(string s) {
        vector<int> vis(101,-1);
        return dp(s, 0, vis);
    }
};
