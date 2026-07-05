class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> concat(nums);
        for(int x:nums) concat.push_back(x);

        return concat;
    }
};