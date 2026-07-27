class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int sum=0;
        int i=0;
        int n = s.length();
        while(i<n) {
            if(i<n-1 && mp[s[i]]<mp[s[i+1]]) {
                sum += mp[s[i+1]]-mp[s[i]];
                i+=2;
            } else {
                sum += mp[s[i]];
                i+=1;
            }
        }

        return sum;
    }
};