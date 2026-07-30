class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // without modifing actual array
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;

        // int cnt=0;
        // for(int i=0; i<nums.size(); i++) {
        //     if(nums[i] == val) {
        //         erase(nums, val);
        //         cnt++;
        //     }
        // }
        // sort(nums.begin(), nums.end());

        // return nums.size();
    }
};