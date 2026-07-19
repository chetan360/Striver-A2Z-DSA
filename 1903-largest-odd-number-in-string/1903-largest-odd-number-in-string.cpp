class Solution {
public:
    string largestOddNumber(string num) {
        // phiche se odd deko
        // 0 se ustak substring lelo
        for(int i=num.length()-1; i>=0; i--) {
            if((num[i] - '0')%2!=0)
                return num.substr(0, i+1);
        }
        return "";
    }
};