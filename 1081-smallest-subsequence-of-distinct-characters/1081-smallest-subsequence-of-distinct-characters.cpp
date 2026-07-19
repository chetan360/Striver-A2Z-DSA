class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> visited(26), freq(26);
        for(char ch:s)
            freq[ch-'a']++;
        
        string stk;
        for(char ch:s) {
            if(!visited[ch-'a']) {
                while(!stk.empty() && stk.back()>ch) {
                    if(freq[stk.back()-'a'] > 0) {
                        visited[stk.back()-'a'] = 0;
                        stk.pop_back();
                    } else break;
                }
                visited[ch-'a'] = 1;
                stk.push_back(ch);
            }
            freq[ch-'a'] -= 1;
        }

        return stk;
    }
};