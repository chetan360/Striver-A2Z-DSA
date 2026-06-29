class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0, up=nums.size()-1;
        while(low<=up) {
            // Time limit int range
            int mid = low + (up-low)/2;
            if(target == nums[mid]) {
                return mid;
            } else if(target < nums[mid]) {
                up = mid-1;
            } else {
                low = mid+1;
            }
        }

        return -1;
    }
};