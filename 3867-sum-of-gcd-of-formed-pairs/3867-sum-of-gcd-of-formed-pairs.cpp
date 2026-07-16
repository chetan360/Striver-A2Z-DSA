class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        vector<int> preMax(n);
        vector<int> preGcd(n);
        preGcd[0] = nums[0];
        preMax[0] = nums[0];

        for(int i=1; i<n; i++) {
            preMax[i] = max(preMax[i-1], nums[i]);
            preGcd[i] = gcd(nums[i], preMax[i]);
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