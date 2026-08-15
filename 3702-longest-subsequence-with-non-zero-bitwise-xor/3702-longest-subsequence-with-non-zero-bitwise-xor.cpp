class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0, zeros = 0;
        int n = nums.size();
        for(int num:nums) {
            totalXor ^= num;
            if(num == 0) zeros++;
        }

        if(totalXor == 0) {
            if(zeros == n) return 0; //all elt are zero
            return nums.size()-1; //even no. of set bit remove 1 no.
        }

        return n;
    }
};
