class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; ;i++) {
            int prod=1;
            
            int temp = i;
            while(temp!=0) {
                int r = temp%10;
                prod *= r;
                temp /= 10;
            }

            if(prod%t==0) return i;
        }
    }
};