class Solution {
static inline string s[] = {"Bob", "Tie", "Alice"};
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[4] = {0, 0, 0, 0}; // curcular buffer

        for(int i=n-1; i>=0; i--) {
            // take 1 stone
            dp[i&3] = stoneValue[i] - dp[(i+1)&3];

            // take 2 stones
            if(i+2<=n)
                dp[i&3] = max(dp[i&3], stoneValue[i]+stoneValue[i+1]-dp[(i+2)&3]);
            // take 3 stones
            if(i+3<=n)
                dp[i&3] = max(dp[i&3], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[(i+3)&3]);
        }

        // map relative score to answer string
        return s[(dp[0]>0)-(dp[0]<0)+1];
    }
};