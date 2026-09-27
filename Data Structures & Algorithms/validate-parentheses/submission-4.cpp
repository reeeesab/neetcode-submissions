class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(auto ch: s){
            if(ch == '(' || ch=='[' || ch=='{'){
                st.push(ch);
            }else{
                if(st.empty()) return false;
                char opening = st.top();
                st.pop();
                 if(ch == ')' && opening!='(') return false; 
                 if(ch == ']' && opening!='[') return false; 
                 if(ch == '}' && opening!='{') return false; 
            }
        }
        return st.empty();
    }
};