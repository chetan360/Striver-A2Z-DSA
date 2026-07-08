class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr_sum = 0;
        int max_sum = INT_MIN;

        // kadane's algorithm
        for(int x: nums) {
           curr_sum = max(x, curr_sum + x); 
            max_sum = max(curr_sum, max_sum);
        }

        return max_sum;
    }
};