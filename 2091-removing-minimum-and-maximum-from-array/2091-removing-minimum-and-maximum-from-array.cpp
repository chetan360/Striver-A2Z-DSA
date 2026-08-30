class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        
        //for left never cross right
        int left=min(minIdx, maxIdx);
        int right=max(minIdx, maxIdx);

// min of (right elt left part(overlap) del, right elt right part del, both side del)
        return min(right+1, min(n-left, left+1+n-right));
    }
};