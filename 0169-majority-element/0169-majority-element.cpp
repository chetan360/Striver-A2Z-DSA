class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // map<int,int> freqMap;
        // for(int x: nums) {
        //     freqMap[x]++;
        // }
        
        // for(auto it: freqMap) {
        //     if(it.second > nums.size()/2) {
        //         return it.first;
        //     }
        // }
        
        // return -1;

        //boyer moore algorithm
        int n = nums.size();
        int elt, cnt=0;
        for(int i=0; i<n; i++) {
            if(cnt==0) {
                elt = nums[i];
                cnt=1;
            } else if(nums[i]==elt) {
                cnt++;
            } else {
                cnt--;
            }
        }

        int cnt1=0;
        for(int x:nums) {
            if(x==elt) cnt1++;
        }

        if(cnt1>n/2) return elt;

        return -1;
    }
};