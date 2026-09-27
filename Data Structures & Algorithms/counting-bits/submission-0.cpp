class Solution {
public:
    int bits(int n){
        int cnt = 0;
        while(n){
            n = n & (n -1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        int i = 0;
        while(i<=n){
            ans.push_back(bits(i++));
        }

        return ans;
    }
};
