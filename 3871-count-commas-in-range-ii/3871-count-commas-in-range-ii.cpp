class Solution {
using ll=long long;
public:
    long long countCommas(long long n) {
        ll cnt=0;
        //math + place value
        for(ll p=1000; p<=n; p*=1000) {
            cnt += n-p+1; 
        }

        return cnt;
    }
};