class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        // n=1, unique xors=1
        // n=2, unique xors=2
        if(n<=2)
            return n;
        
        // n>=3 i.e. now 2^(k+1) strictly > n
        int ans=1;
        while(ans<=n)
            ans <<= 1;
        return ans;
    }
};