class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false; //2^0 = 1
        return (n&n-1)==0; //e.g 2^3=8, 8&7 => 1000&0111=0
    }
};