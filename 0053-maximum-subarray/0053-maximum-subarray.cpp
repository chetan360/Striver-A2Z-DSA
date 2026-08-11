class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //kadane's algorithm
        int sum=0;
        int maxSum=INT_MIN;
        for(int x:nums) {
            sum += x;
            maxSum = max(maxSum, sum);
            if(sum<0) sum=0;
        }
        
        return maxSum;
    }
};