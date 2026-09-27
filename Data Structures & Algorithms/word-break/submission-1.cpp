class Solution {
public:
    bool dp(string s, int i, vector<string>& wordDict, vector<int> &vis){
        if(i>=s.size()) return true;
        if(vis[i]!=-1) return vis[i];

        for(int j = 0; j<wordDict.size(); j++){
            string newS = wordDict[j];
            int k;
            if(i+newS.size()>s.size()) continue;
            for(k = 0; k<newS.size(); k++){
                if(s[k+i]!=newS[k]) break;
            }

            if(k == newS.size()) {
                if(dp(s, i + k, wordDict, vis)) {
                    return vis[i]=true;
                }
            }
        }
        return vis[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> vis(201, -1);
        return dp(s, 0, wordDict, vis);
    }
};
