class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;

        vector<int> preGcd(n);
        preGcd[0] = nums[0];
        int prevMax=nums[0];
        for(int i=1; i<n; i++) {
            int currMax = max(prevMax, nums[i]);
            preGcd[i] = gcd(nums[i], currMax);
            prevMax = currMax;
        }

        sort(preGcd.begin(), preGcd.end());
        long long sum = 0;
        int left = 0, right = n-1;
        while(left<right) {
            sum += gcd(preGcd[left++], preGcd[right--]);
        }
        return sum;
    }
};