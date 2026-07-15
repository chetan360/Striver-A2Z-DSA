class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> dp(m+1, vector<int>(m+1));
        dp[0][0] = 1;

        for(int x:nums) {
            vector<vector<int>> ndp(m+1, vector<int>(m+1));
            for(int j=0; j<=m; j++) {
                int g1 = gcd(j, x);
                for(int k=0; k<=m; k++) {
                    int val = dp[j][k];
                    if(val==0) continue;
                    int g2 = gcd(k, x);
                    // ignore
                    ndp[j][k] = (ndp[j][k]+val) % MOD;
                    // store in seq1
                    ndp[g1][k] = (ndp[g1][k]+val) % MOD;
                    // store in seq2
                    ndp[j][g2] = (ndp[j][g2]+val) % MOD;
                }
            }
            dp.swap(ndp);
        }

        int ans=0;
        for(int j=1; j<=m; j++) 
            ans = (ans+dp[j][j]) % MOD;

        return ans;
    }
};