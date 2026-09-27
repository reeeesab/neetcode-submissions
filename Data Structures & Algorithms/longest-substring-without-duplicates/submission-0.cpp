class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        queue<char> charQueue;
        set<char> uniqueChars;
        int globalMax = 0;
        for(auto singleChar: s){
            if(uniqueChars.find(singleChar)!=uniqueChars.end()){
                globalMax = max(globalMax, (int)charQueue.size());
               while(singleChar != charQueue.front()){
                    uniqueChars.erase(charQueue.front());
                    charQueue.pop();
               }
               charQueue.pop();
               uniqueChars.erase(singleChar);
               charQueue.push(singleChar);
               uniqueChars.insert(singleChar);
            }else{
                uniqueChars.insert(singleChar);
                charQueue.push(singleChar);
            }
        }
        globalMax = max(globalMax, (int)charQueue.size());
        return globalMax;
    }
};
