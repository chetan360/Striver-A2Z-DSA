class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int, int> numRank;
        set<int> nums(arr.begin(), arr.end());
        
        int rank=1;
        for(auto x: nums) 
            numRank[x] = rank++;
        for(int i=0; i<arr.size(); i++) 
            arr[i] = numRank[arr[i]];

        return arr;
    }
};