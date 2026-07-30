class Solution {
private:
    void backtrack(vector<vector<int>> &res, vector<int> curr, int st, int n, int k) {
        // if combi. is completed then  puch it back to res
        if(curr.size() == k) {
            res.push_back(curr);
            return;
        }
        for(int i=st; i<=n-(k-curr.size())+1; i++) {
            //pusing i
            curr.push_back(i);
            //pasing i+1 next permu. to build req. combi.
            backtrack(res, curr, i+1, n, k);
            curr.pop_back();
            // empty curr for next combi.
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curr;
        //calculate combination of k chosen from [1,n] 
        backtrack(res, curr, 1, n, k);
        return res;
    }
};