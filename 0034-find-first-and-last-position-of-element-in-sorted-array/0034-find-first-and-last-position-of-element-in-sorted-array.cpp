class Solution {
public:
    int lowerBound(vector<int>& nums, int target) {
        int n=nums.size();
        int lb=n;
        int l=0, r=n-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid]>=target) {
                lb = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return lb;
    }

    int upperBound(vector<int>& nums, int target) {
        int n=nums.size();
        int ub=n;
        int l=0, r=n-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid]>target) {
                ub = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }

        return ub;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, target);
        if(lb==n || nums[lb]!=target) return {-1,-1};
        return {lb, upperBound(nums, target) -1};
    }
};