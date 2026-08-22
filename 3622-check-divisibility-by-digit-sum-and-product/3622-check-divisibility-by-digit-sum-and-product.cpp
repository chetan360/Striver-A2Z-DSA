class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int t = n;
        while(t!=0) {
            int r = t%10;
            sum += r;
            t /= 10;
        }

        t=n;
        int prod = 1;
        while(t!=0) {
            int r = t%10;
            prod *= r;
            t /= 10;
        }

        sum += prod;

        return n%sum==0;
    }
};