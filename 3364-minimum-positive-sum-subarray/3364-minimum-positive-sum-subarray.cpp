class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int mini = INT_MAX;
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        partial_sum(nums.begin(), nums.end(), prefix.begin()+1);
        for(int i=l; i<=r; i++) {
            for(int j=0; j+i<=n; j++) {
                int sum = prefix[j+i]-prefix[j];
                if(sum>0) mini = min(mini, sum);
            }
        }

        return (mini==INT_MAX)?-1:mini;
    }
};