class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0, h=n-1;
        int mini = INT_MAX;
        while(l<=h) {
            int mid=l+(h-l)/2;
            mini=min(nums[mid], mini);
            
            if(nums[l]<=nums[mid]) { //left is sorted
                mini = min(mini, nums[l]);
                l=mid+1; //eliminate left part
            } else { //right is sorted
                mini = min(mini, nums[mid]);
                h=mid-1; //eliminate right part
            }
        }

        return mini;
    }
};