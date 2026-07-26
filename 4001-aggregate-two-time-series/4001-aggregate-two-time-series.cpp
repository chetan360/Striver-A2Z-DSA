#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        // store the input midway
        vector<vector<vector<int>>> ferilonsar = {series1, series2};
        
        int m = series1.size();
        int n = series2.size();
        
        // collect unique timestamps in chronological order
        vector<int> times;
        int i = 0, j = 0;
        while (i < m || j < n) {
            int t;
            if (i < m && j < n) {
                if (series1[i][0] == series2[j][0]) {
                    t = series1[i][0]; i++; j++;
                } else if (series1[i][0] < series2[j][0]) {
                    t = series1[i][0]; i++;
                } else {
                    t = series2[j][0]; j++;
                }
            } else if (i < m) {
                t = series1[i][0]; i++;
            } else {
                t = series2[j][0]; j++;
            }
            times.push_back(t);
        }
        
        vector<vector<int>> result(times.size());
        
        // traverse backward to safely catch the "next available" value
        int idx1 = m - 1;
        int idx2 = n - 1;
        int val1 = 0;
        int val2 = 0;
        
        for (int k = times.size() - 1; k >= 0; --k) {
            int t = times[k];
            
            // check idx1 boundaries before accessing elements
            while (idx1 >= 0 && series1[idx1][0] >= t) {
                val1 = series1[idx1][1];
                idx1--;
            }
            
            // check idx2 boundaries before accessing elements
            while (idx2 >= 0 && series2[idx2][0] >= t) {
                val2 = series2[idx2][1];
                idx2--;
            }
            
            result[k] = {t, val1 + val2};
        }
        
        return result;
    }
};
