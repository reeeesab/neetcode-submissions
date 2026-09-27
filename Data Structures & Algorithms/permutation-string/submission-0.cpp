class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> completeFreq(26,0);
        vector<int> windowFreq(26,0);

        int sizeOfSubstring = s1.size();
        int sizeOfString = s2.size();

        for(auto singleChar: s1){
            windowFreq[singleChar - 'a']++;
        }

        for(int i = 0; i<sizeOfSubstring; i++){
            completeFreq[s2[i]-'a']++;
        }


        int left = 0, right = sizeOfSubstring-1;
        while(right<sizeOfString){
            if(windowFreq == completeFreq) return true;
            completeFreq[s2[left]-'a']--;
            left++;
            right++;
            completeFreq[s2[right]-'a']++;
            
        }
        return false;
    }
};
