class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        
        int currElt = nums[0];
        for(int i=0; i<nums.size(); currElt++, i++) {
            if(currElt < nums[i]) {
                res.push_back(currElt);
                i--;
            }
        }

        return res;
    }
};