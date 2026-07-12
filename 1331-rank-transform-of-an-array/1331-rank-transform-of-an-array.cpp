class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        //for store number and its rank
        unordered_map<int, int> numRank;
        //remove duplicates and sort arr 
        set<int> nums(arr.begin(), arr.end());
        
        int rank=1;
        //key=num, value=rank
        for(auto x: nums) 
            numRank[x] = rank++;
        for(int i=0; i<arr.size(); i++) 
            arr[i] = numRank[arr[i]];

        return arr;
    }
};