#include <cstring>
class Solution {
public:
    int vis[1001][1001];
    int dp(string text1, string text2, int i, int j) {
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }

       if(vis[i][j]!=-1) return vis[i][j];
       
         if (text1[i] == text2[j]) {

            return vis[i][j] = 1 + dp(text1, text2, i + 1, j + 1);
        }

         return vis[i][j]= max(
            dp(text1, text2, i + 1, j),
            dp(text1, text2, i, j + 1)
        );
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(vis, -1, sizeof(vis));
        return dp(text1, text2, 0 , 0);
    }
};
