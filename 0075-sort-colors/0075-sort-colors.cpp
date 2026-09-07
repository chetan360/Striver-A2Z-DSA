class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algorithm
        int low=0, mid=0, high=nums.size()-1;
        while(mid<=high) {
            if(nums[mid]==0) { //0's in 0 to low-1
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if(nums[mid]==1) { //1's in low to mid-1
                mid++;
            //mid to high (unsorted)
            } else { //2's in high+1 to n-1
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};