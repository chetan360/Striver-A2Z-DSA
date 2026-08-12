class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freqMap;
        int l=0, maxLen=0;
        for(int r=0; r<n; r++) {
            //expanding window by adding curr elt and its freq 
            freqMap[nums[r]]++; 
            
            //shrinking window if its not good subarray 
            //remove left most elt and also decreasing its count 
            while(freqMap[nums[r]]>k) {
                freqMap[nums[l]]--;
                l++;
            }

            maxLen = max(maxLen, r-l+1);
        }

        return maxLen;
    }
};