class Solution {
public:
    int maxProduct(int n) {
        vector<int>digits;
        while(n>0) {
            digits.push_back(n%10);
            n /= 10;
        }

        // second largest in array
        int l=digits[0];
        int sl=-1;
        for(int i=1; i<digits.size(); i++) {
            if(digits[i]>l) {
                sl = l;
                l = digits[i];
            } else if(digits[i]>sl && sl!=l)
                sl = digits[i];
        }

        return l*sl;
    }
};