class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxOnes = 0, ones=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==1) ones++;
            else ones=0;
            maxOnes = max(ones, maxOnes);
        }

        return maxOnes;
    }
};