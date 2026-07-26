class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        // geast integer is beacomes least integer if we change sign
        return max(
            nums[0]*nums[1]*nums[n-1], // two smallest(for -ve case) one largest
            nums[n-1]*nums[n-2]*nums[n-3]); // three largest
    }
};