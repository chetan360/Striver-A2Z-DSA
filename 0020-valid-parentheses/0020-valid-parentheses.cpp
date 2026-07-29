class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {')','('},
            {'}','{'},
            {']','['}
        };
        if(s == "") return false;
        stack<char> stk;
        int n = s.length();
         for(int i=0; i<n; i++) {
            if(s[i]=='(' || s[i]=='{' || s[i] == '[')
                stk.push(s[i]);
            else {
                if(stk.empty() || stk.top()!=mp[s[i]]) return false;
                stk.pop();
            }
        }
        return stk.empty();
        return false;
    }
};