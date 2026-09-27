#include <cstring>
class Solution {
public:
    int dp[101][101];
    int mins(string& word1, int i, string& word2, int j) {

        // word1 exhausted
        if(i >= word1.size())
            return word2.size() - j;

        // word2 exhausted
        if(j >= word2.size())
            return word1.size() - i;

        if(dp[i][j]!=-1) return dp[i][j];
        // characters match
        if(word1[i] == word2[j])
            return dp[i][j]=  mins(word1, i+1, word2, j+1);

        int insertOp = 1 + mins(word1, i, word2, j+1);

        int deleteOp = 1 + mins(word1, i+1, word2, j);

        int replaceOp = 1 + mins(word1, i+1, word2, j+1);

        return dp[i][j]=  min(insertOp, min(deleteOp, replaceOp));
    }

    int minDistance(string word1, string word2) {
        memset(dp,-1, sizeof(dp));
        return mins(word1, 0, word2, 0);
    }
};