class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int len = 0;
        for(int i=0; i<n; i++) {
            int preProd = nums[i];
            int preGcd = nums[i];
            int preLcm = nums[i];
            for(int j=i+1; j<n; j++) {
                preProd = preProd * nums[j];
                preGcd = gcd(preGcd, nums[j]);
                preLcm = lcm(preLcm, nums[j]);

                if(preProd>preGcd*preLcm) break;
                else if(preProd==preGcd*preLcm) {
                    len = max(len, j-i+1);
                }
            }
        }

        return len;
    }
};