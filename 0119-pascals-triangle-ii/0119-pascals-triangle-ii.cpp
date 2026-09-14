class Solution {
private:
    vector<int> generateRow(int n) {
        vector<int> row;
        __int128 ans=1;
        row.push_back(ans);
        
        for(int col=1; col<n; col++) {
            ans *= (n-col);
            ans /= col;
            row.push_back((int)ans);
        }

        return row;
    }

public:
    vector<int> getRow(int rowIndex) {
        return generateRow(rowIndex+1);
    }
};