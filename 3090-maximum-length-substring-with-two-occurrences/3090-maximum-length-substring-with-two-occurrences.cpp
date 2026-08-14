class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxLen = 0;
        int n = s.size();
        unordered_map<char, int> mpp;
    
        int l = 0;
        for(int r=0; r<n; r++) {
            mpp[s[r]]++;
            while(mpp[s[r]]>2) {//shrink window curr char occr > 2
                mpp[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};