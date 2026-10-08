class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int depth=0;
        for(auto ch: s) {
            if(ch=='(') {
                depth++;
                if(depth>1) res += ch;
            } else if(ch==')') {
                depth--;
                if(depth>0) res += ch;
            }
        }

        return res;
    }
};