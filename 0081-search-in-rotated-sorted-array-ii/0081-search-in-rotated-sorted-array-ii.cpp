class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, h=n-1;
        while(l<=h) {
            int mid=l+(h-l)/2;
            if(nums[mid]==target) return true;

            //skipping douplicates nums[l]=nums[mid]=nums[h]
            if(nums[l]==nums[mid] && nums[mid]==nums[h]) {
                l++;
                h--;
                continue;
            }

            if(nums[l]<=nums[mid]) {//left part sorted
                if(nums[l]<=target && target<=nums[mid]) {
                    h=mid-1;
                } else {
                    l=mid+1;
                }
            } else { //right part sorted
                if(nums[mid]<=target && target<=nums[h]) {
                    l=mid+1;
                } else {
                    h=mid-1;
                }
            }
        }

        return false;
    }
};