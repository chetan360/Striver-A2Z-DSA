class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // int n = nums.size();
        // for(int i=0; i<n; i++) {
        //     int l=0, r=n-1;
        //     int lSum=0, rSum=0;
        //     while(l<i) {
        //         lSum += nums[l];
        //         l++;
        //     }
        //     while(r>i) {
        //         rSum += nums[r];
        //         r--;
        //     }
        //     if(lSum==rSum) return i;
        // }

        // return -1;

        int n = nums.size();
        int totalSum = 0;
        for(int x:nums) totalSum+=x;

        int lSum = 0;
        for(int i=0; i<n; i++) {
            int rSum = totalSum - lSum - nums[i];
            if(lSum==rSum) return i;
            lSum += nums[i];
        }

        return -1;
    }
};