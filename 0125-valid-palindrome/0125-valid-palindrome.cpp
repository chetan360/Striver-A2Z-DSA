class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        while(i<j) {
            while(i<n && !isalnum(s[i])) i++;
            while(j>=0 && !isalnum(s[j])) j--;
            if(i<j) {
                char a = s[i];
                if(a>='A' && a<='Z') a = a-'A'+'a';
                
                char b = s[j];
                if(b>='A' && b<='Z') b = b-'A'+'a';
                if(a!=b) return false;
            }
            i++, j--;
        }
        return true;
    }
};