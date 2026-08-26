class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int minLen = INT_MAX;
        int left=0, ones=0;
        string res="";
        for(int right=0; right<n; right++) {
            if(s[right]=='1') {
                ones++;
            }
            while(ones>k && left<=right) {
                if(s[left]=='1') ones--;
                left++;
            }

            if(ones==k) {
                while(left<=right && s[left]=='0') left++;
                int len = right-left+1;
                string curr = s.substr(left, len);
                if(res.empty()) {
                    res = curr;
                    minLen = len;
                    continue;
                }
                if(len<minLen || (len==minLen && curr<res)) {
                    minLen = len;
                    res = curr;
                }
            }
        }

        return res;
    }
};