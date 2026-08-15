class Solution {
private:
    vector<int> genRow(int row) {
        vector<int> ansRow;
        ansRow.push_back(1);
        long long ans = 1; //1
        for(int col=1; col<row; col++) {
            ans *= (row-col);
            ans /= col;// 1, 4/1, 4*3/1*2, 4*3*2/1*2*3, 4*3*2*1/1*2*3*4
            ansRow.push_back(ans); //[1,4,6,4,1]
        }
        return ansRow;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=1; i<=numRows; i++) {
            ans.push_back(genRow(i));
        }

        return ans;
    }
};