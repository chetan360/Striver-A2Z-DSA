class Solution {
    int gcd(int a, int b) {
        while(b!=0) {
            a = a%b;
            //swap a & b
            int t = a;
            a = b;
            b = t;
        }

        return a;
    }

    public int commonFactors(int a, int b) {
        if(b>a) {
            int t = a;
            a = b;
            b = t;
        }

        // a > b for gcd logic
        int cnt=1;
        for(int i=2; i<=gcd(a,b); i++) {
            if(a%i==0 && b%i==0) cnt++;
        }

        return cnt;
    }
}