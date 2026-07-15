class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // if(n==1) return 1;
        // int sumEven=0, sumOdd=0;
        // for(int i=1; i<=n*2; i++) {
        //     if(i%2==0) 
        //         sumEven++;
        //     else 
        //         sumOdd++;
        // }
        // return gcd(sumOdd, sumEven);

        // gcd of odd, even = gcd of n, n+1 (consecative numbers coprime) always 1
        // sum of odd = n^2
        // sum of even = n*(n+1)
        // gcd(n*n, n*(n+1)) = n*gcd(n, (n+1))
        return n;
    }
};