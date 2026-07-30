class Solution {
private:
    void backtrack(vector<vector<int>> &res, vector<int> curr, int st, int n, int k) {
        if(curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for(int i=st; i<=n-(k-curr.size())+1; i++) {
            curr.push_back(i);
            backtrack(res, curr, i+1, n, k);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        backtrack(res, curr, 1, n, k);
        return res;
    }
};