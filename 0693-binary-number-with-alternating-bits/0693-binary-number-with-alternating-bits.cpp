class Solution {
public:
    bool hasAlternatingBits(int n) {
        string bits = "";
        bits += to_string(n%2);
        n /= 2;
        for(int i=1; n>0; i++) {
            bits += to_string(n%2);
            n /= 2;
            if(bits[i-1] == bits[i]) return false;
        }

        return true;
    }
};