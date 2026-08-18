class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            if(ans.empty() || intervals[i][0]>ans.back()[1]) {//empty or not lying in interval
                ans.push_back(intervals[i]);
            } else {//lying
                ans.back()[1] = max(ans.back()[1],intervals[i][1]);
            }
        }

        return ans;
    }
};