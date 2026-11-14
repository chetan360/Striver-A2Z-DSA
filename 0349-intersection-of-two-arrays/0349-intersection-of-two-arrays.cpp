class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int x:nums1)
            s1.insert(x);

        unordered_set<int> s2;
        for(int x:nums2)
            s2.insert(x);
        
        erase_if(s1, [&s2](int x) {
            return !s2.contains(x);
        });

        vector<int> ans;
        for(auto x:s1)
            ans.push_back(x);
        
        return ans;
    }
};