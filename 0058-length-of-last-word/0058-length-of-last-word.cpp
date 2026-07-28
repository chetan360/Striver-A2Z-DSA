class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        int n = s.length();
        if(n==0) return 0;

        int i=n-1;
        while(i>=0 && s[i] == ' ') i--;
        int j = i-1;
        while(j>=0 && s[j] != ' ') j--;

        return i-j;
    }
};