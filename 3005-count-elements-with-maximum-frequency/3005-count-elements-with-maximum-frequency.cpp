class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int hash[1000000] = {0};
        int max_freq=0;
        for(int x: nums) {
            hash[x]++;
            if(hash[x]>max_freq) max_freq = hash[x];   
        }

        int total=0;
        for(int x: hash) {
            if(x==max_freq) total += x;
        }

        return total;
    }
};