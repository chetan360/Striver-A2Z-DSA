class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        unordered_map<char, int> mpp;
        for(char ch:s) {
            mpp[ch]++;
        }

        for(char ch:t) {
            //if not in map or freq is 0
            if(mpp.find(ch) == mpp.end() || mpp[ch]==0) return false;
            mpp[ch]--; //decrease count
        }

        return true;
    }
};