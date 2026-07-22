class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<=k-1; i++) {
            sum += nums[i];
        }

        int mxSum = sum;
        for(int i=k; i<n; i++) {
            sum = sum + nums[i]; // add right
            sum = sum - nums[i-k]; // sub left
            mxSum = max(mxSum, sum);
        }

        return (double)mxSum/k;
    }
};