class Solution {
public:
    string smallestPalindrome(string s) {
        // counting sort 
        int n=s.length();
        int bucket[26] = {0};
        
        for(int i=0; i<n/2; i++)
            bucket[s[i]-'a']++;
        
        int l=0;
        int r=n-1;
        for(int i=0; i<26; i++) {
            while(bucket[i]>0) {
                char ch = i+'a';
                s[l++] = ch;
                s[r--] = ch;
                bucket[i]--;
            }
        }

        return s;
    }
};