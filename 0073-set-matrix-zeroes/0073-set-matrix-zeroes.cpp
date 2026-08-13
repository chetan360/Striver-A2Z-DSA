class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //matrix[..][0] row
        //matrix[0][..] col
        int n = matrix.size();//rows
        int m = matrix[0].size();//col
        int col0=1;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j]==0) {
                    //mark i'th row
                    matrix[i][0] = 0;
                    //mark j'th col
                    if(j!=0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0; //1'st col matrix[0][0]
                }
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(matrix[i][j]!=0) {
                    if(matrix[0][j]==0 || matrix[i][0]==0) {
                        matrix[i][j] = 0;
                    }
                }
            }
        }

        //checking col 1'st
        if(matrix[0][0]==0) {
            for(int j=0; j<m; j++) matrix[0][j]=0;
        }
        //then checking row
        if(col0==0) {
            for(int i=0; i<n; i++) matrix[i][0]=0;
        }
    }
};