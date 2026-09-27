class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> hash;

        for(char c : t) {
            hash[c]++;
        }

        int left = 0;
        int right = 0;

        int cnt = 0;

        int minLen = INT_MAX;
        int start = -1;

        while(right < s.size()) {

            // useful character
            if(hash[s[right]] > 0) {
                cnt++;
            }

            hash[s[right]]--;

            // valid window
            while(cnt == t.size()) {

                // update answer FIRST
                if(right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                hash[s[left]]++;

                // needed char removed
                if(hash[s[left]] > 0) {
                    cnt--;
                }

                left++;
            }

            right++;
        }

        return start == -1
               ? ""
               : s.substr(start, minLen);
    }
};