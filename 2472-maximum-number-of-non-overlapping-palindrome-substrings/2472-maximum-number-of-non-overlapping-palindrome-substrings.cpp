class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int cnt = 0;
        int last_end = -1; // Keeps track of the end of the last picked palindrome

        // Helper function to check if a substring is a palindrome
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        // Iterate through all possible ending positions
        for (int i = 0; i < n; i++) {
            // Check for palindrome of length k ending at i
            int start1 = i - k + 1;
            if (start1 > last_end && isPalindrome(start1, i)) {
                cnt++;
                last_end = i;
            } 
            // Check for palindrome of length k + 1 ending at i
            else {
                int start2 = i - k;
                if (start2 > last_end && isPalindrome(start2, i)) {
                    cnt++;
                    last_end = i;
                }
            }
        }
        return cnt;
    }
};
