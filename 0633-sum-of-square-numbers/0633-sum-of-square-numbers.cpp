class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a=0; a*a<=c; a++) {
            // pythagorous thm jesa
            // h^2 = a^2+b^2
            // sqrt(h^2-a^2) = c
            double b = sqrt(c-a*a);
            // b sirf int ho to pythagorous thm satisfy ho gaya
            if(b == (int)b) return true;
        }

        return false;
    }
};