class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {}; // Handle empty input edge case
        sort(intervals.begin(), intervals.end());
        vector<int> curr;
        vector<vector<int>> res;
        int n = intervals.size();
        curr = intervals[0];
        for(int i=1; i<n; i++) {
            // If current interval overlaps with the next one
            if(intervals[i][0]<=curr[1])
                curr[1] = max(curr[1], intervals[i][1]);
            else {
                res.push_back(curr);
                curr = intervals[i];
            }
        }
        res.push_back(curr);
        return res;
    }
};