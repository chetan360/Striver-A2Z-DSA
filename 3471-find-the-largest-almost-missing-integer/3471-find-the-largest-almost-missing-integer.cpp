class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        // generating k size sub arrays
        for(int i=0; i<=n-k; i++) {
            // sliding widow
            unordered_set<int> s(nums.begin()+i, nums.begin()+i+k);
            for(int num:s) {
                freq[num]++;
            }
        }

        int maxi = -1;
        for(auto num:freq) {
            if(num.second==1) {
                maxi = max(maxi, num.first);
            }
        }

        return maxi;
    }
};