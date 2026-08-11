class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int preSum=nums[0];
        for(int i=1; i<nums.size(); i++) {
            //if curr = prev+1
            if(nums[i]==nums[i-1]+1) {
                preSum+=nums[i];
            } else {
                break;
            }
        }

        unordered_set<int> us(nums.begin(), nums.end());
        while(true) {
            //not in set
            if(us.find(preSum)==us.end()) {
                return preSum;
            }
            preSum++;
        }
    }
};