class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        int lastA = -1;
        int firstB = n;
        for(int i=0; i<n; i++) {
            if(s[i]=='a') lastA = max(lastA, i);
            else firstB = min(firstB, i); 
        }

        return lastA < firstB;
    }
};