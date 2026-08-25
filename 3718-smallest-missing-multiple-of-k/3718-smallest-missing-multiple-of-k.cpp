class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        // brute: T.C.= O(nlogn + O(n)), S.C = O(1)
        // int n = nums.size();
        // int last = -1;
        // sort(nums.begin(), nums.end());
        // int multi = k;
        // for(int num:nums) {
        //     if(num<multi) continue;
        //     else if(num==multi) multi+=k;
        // }
        
        // return multi;

        // optimal: T.C. = O(2n), S.C = O(1) 
        unordered_set<int>s(nums.begin(), nums.end());
        int multi = k;
        while(s.count(multi)) multi+=k;

        return multi;
    }
};