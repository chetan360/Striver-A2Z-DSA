class Solution {
public:
    int minimumPushes(string word) {
        // int n = word.size();
        // int ans = 0;
        // // ith letteer position is [i/8]+1
        // // [] is G.I.F
        // for(int i=0; i<n; i++)
        //     ans += (i/8)+1;
        // return ans;
        int n = word.size();
        int m = (n-1)/8 + 1;
        return 4*m*(m-1) + (n-8*(m-1))*m;
    }
};