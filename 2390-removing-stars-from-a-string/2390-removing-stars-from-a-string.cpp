class Solution {
public:
    string removeStars(string s) {
        stack<int> stk;
        for(auto c:s) {
            if(c=='*') stk.pop();
            else stk.push(c);
        }

        string res;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};