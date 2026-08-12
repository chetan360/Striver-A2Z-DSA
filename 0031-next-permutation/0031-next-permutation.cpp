class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // next_permutation(nums.begin(), nums.end());
        
        //step1. find the longest prefix match(dip)
        int n = nums.size();
        int dip = -1;
        for(int i=n-2; i>=0; i--) {
            if(nums[i]<nums[i+1]) {
                dip = i;
                break;
            }
        }

        if(dip==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        //step2. find the elt > dip but smallest in rem
        for(int i=n-1; i>dip; i--) {
            if(nums[i]>nums[dip]) {
                swap(nums[i], nums[dip]);
                break;
            }
        }

        //step3. reverse rem elts
        reverse(nums.begin()+dip+1, nums.end());
    }
};