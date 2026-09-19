class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // auto it= lower_bound(nums.begin(), nums.end(), target);
        // return distance(nums.begin(), it);

        int n=nums.size();
        int ans=n;
        int l=0, r=n-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid]>=target) {
                r=mid-1;
                ans=mid;
            } else {
                l=mid+1;
            }
        }

        return ans;
    }
};