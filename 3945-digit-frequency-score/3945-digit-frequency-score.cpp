class Solution {
public:
    int digitFrequencyScore(int n) {
        // unordered_map<int, int> m;
        // while(n>0) {
        //     int d = n%10;
        //     n /= 10;
        //     m[d]++;
        // }
        // int sum=0;
        // for(auto x:m)
        //     sum += x.first*x.second;
        // return sum;

        // sum of unique digets multiply by frequency is
        // actually sum of digits itself
        int sum=0;
        while(n>0) {
            int d = n%10;
            sum += d;
            n /= 10;
        }
        return sum;
    }
};