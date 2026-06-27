class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(i<j) {
            while(i<n && !isalnum(s[i])) i++; //isalnum checks is it digit or alphabate
            while(j>=0 && !isalnum(s[j])) j--; //skiping s[i],s[j] if not alphanumeric
            if(i<j) {
                if(tolower(s[i])!=tolower(s[j])) return false;
            }
            i++, j--; //two pointers approch
        }
        return true;
    }
};