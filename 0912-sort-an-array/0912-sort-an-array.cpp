class Solution {
public:
    void heapify(vector<int>& nums, int n, int i) {
        int largest = i;
        int l = 2*i+1; // left child
        int r = 2*i+2; // right child

        // left child bada he largest se to swap
        if(l<n && nums[l]>nums[largest])
            largest = l;
        // right child bada he largest se to swap
        if(r<n && nums[r]>nums[largest])
            largest = r;
        
        // largest update ho gaya to swap
        if(largest != i) {
            swap(nums[i], nums[largest]);
            // change huhe subtree ko hipify kardo
            heapify(nums, n, largest);
        }

    }

    void heapSort(vector<int>& nums) {
        int n = nums.size();
        // max heap bana lo
        for(int i=n/2-1; i>=0; i--)
            heapify(nums, n, i);
        
        // har ek keliye heapify kardo
        for(int i=n-1; i>0; i--) {
            // curr root ko end me move kardo
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }
};