class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=nums[0];
        int sm=nums[0];
        for(int x: nums) {
            if(x>mx) mx=x;
            if(x<sm) sm=x;
        }

        return gcd(mx,sm);
    }
};