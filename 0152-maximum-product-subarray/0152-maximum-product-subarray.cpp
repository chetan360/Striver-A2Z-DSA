class Solution {
private:
    using ll = long long;
public:
    int maxProduct(vector<int>& nums) {
        ll maxi=INT_MIN;
        ll pre=1, suff=1;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre *= nums[i];
            suff *= nums[n-i-1];
            maxi = max(maxi, max(pre, suff));
        }

        return (int)maxi;
    }
};