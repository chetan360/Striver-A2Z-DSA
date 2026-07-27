class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int x:nums) 
            if(x%2==0) m[x]++;

        if(m.empty()) return -1;
        int maxFreq = 0;
        int ans = -1;
        for(auto const& [val, freq]:m) {
            if(freq>maxFreq || (freq == maxFreq && val < ans)) {
                maxFreq = freq;
                ans = val;
            }
        }

        return ans;
    }
};