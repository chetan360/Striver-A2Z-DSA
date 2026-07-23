class Solution {
public:
    void solve(vector<string> &res, int n, int open, int close, string curr) {
        if(curr.size() == 2*n) {
            res.push_back(curr);
            return;
        }
        if(open<n)
            solve(res, n, open+1, close, curr+"(");
        if(close<open)
            solve(res, n, open, close+1, curr+")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(res, n, 0, 0, "");
        return res;    
    }
};