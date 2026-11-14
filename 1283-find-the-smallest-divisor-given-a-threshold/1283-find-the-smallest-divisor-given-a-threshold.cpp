class Solution {
public:
    bool possible(vector<int>& nums, int d, int threshold) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += (nums[i]+d-1)/d; //ceil division
        }
        if(sum<=threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());

        while(l<=r) {
            int mid = l+(r-l)/2;
            if(possible(nums, mid, threshold)) r = mid-1;
            else l = mid+1;
        }

        return l;
    }
};