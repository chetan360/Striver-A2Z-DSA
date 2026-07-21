class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.length();
        int prevRun = -1, maxSum=0;
        int i=0, ones = 0;
        while(i<n) {
            if(s[i]=='1') {
                ones++;
                i++;
            } else {
                int currRun=0;
                while(s[i]=='0' && i<n) {
                    currRun++;
                    i++;
                }
                if(prevRun>0)
                    maxSum = max(maxSum, prevRun+currRun);
                prevRun = currRun;
            }
        }

        return ones+maxSum;
    }
};