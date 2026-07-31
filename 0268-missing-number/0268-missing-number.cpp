class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int x:nums)
            freq[x]++;
        int n = nums.size();
        for(int i=0; i<=n; i++)
            if(freq[i]==0)
                return i;
        return -1;
    }
};