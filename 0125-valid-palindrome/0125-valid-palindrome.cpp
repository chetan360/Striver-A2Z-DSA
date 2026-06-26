class Solution {
public:
    bool isPalindrome(std::string s) {
        regex symbol_pattern("[^a-zA-Z0-9]");
        s = regex_replace(s, symbol_pattern, "");
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return tolower(c);
        });
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
};