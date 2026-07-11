class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        long long x = 0;
        while(n>0) {
            int r = n%10;
            n /= 10;
            if(r==0) continue;
            sum += r;
            x = (x*10) + r;
        }
        n=x;
        x=0;
        while(n>0) {
            int r = n%10;
            n /= 10;
            if(r==0) continue;
            x = (x*10) + r;
        }

        return x * sum;
    }
};