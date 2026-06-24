class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) {
            return false;
        }
        long rev=0;
        int rem, temp=x;
        while(temp!=0) {
            rem = temp%10;
            rev = rev*10+rem;
            temp /= 10;
            if(rev>INT_MAX || rev<INT_MIN) {
                return false;
            }
        }
        return x==rev;
    }
};