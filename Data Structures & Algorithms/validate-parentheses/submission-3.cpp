class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i< s.size() ; i++){
            char ch = s[i];
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;
                char openingBracket = st.top();
                st.pop();
                if(openingBracket == '('){
                    if(s[i]!=')') return false;
                }
                if(openingBracket == '{'){
                    if(s[i]!='}') return false;
                }
                if(openingBracket == '['){
                    if(s[i]!=']') return false;
                }
            }
        }
        return st.empty();

    }
};