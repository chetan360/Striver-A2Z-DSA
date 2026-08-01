class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        // checks if n is even
        // if n is even Player 1 always wins.
        // Because Player 1 can control either all odd-indexed or all even-indexed elements by mirroring Player 2's strategy
        if(~n & 1) return true;

        vector dp(n, vector<int>(n, -1));
        auto maxDiff = [&](this auto&& maxDiff, int i, int j) -> int {
            int& res = dp[i][j];
            if(res!=-1) return res;
            // one elt left curr player takes it
            if(i==j) return res = nums[i];

            // We subtract opponent's maxDiff because their advantage becomes our disadvantage!            
            return res = max(nums[i] - maxDiff(i+1, j), nums[j] - maxDiff(i, j-1)); 
        };

        // If Player 1's score difference ≥ 0, they win/tie
        return maxDiff(0, n-1) >= 0;
    }
};

//  Feature	            Purpose
// auto	            Type deduction
// [&]	            Capture external variables by reference
// this auto&&  	Enable recursive lambda (C++23)
// -> int	        Explicit return type
// Lambda	        Keeps helper function scoped locally
