class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // gcd of odd, even = gcd of n, n+1 (consecative numbers coprime) always 1
        // sum of odd = n^2
        // sum of even = n*(n+1)
        // gcd(n*n, n*(n+1)) = n*gcd(n, (n+1))
        return n;
    }
};