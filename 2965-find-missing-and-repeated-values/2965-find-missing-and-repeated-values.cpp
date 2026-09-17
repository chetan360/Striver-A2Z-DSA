class Solution {
    using ll = long long;
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int N=n*n;
        ll SN=N*(N+1)/2;
        ll S2N=(__int128)N*(N+1)*(2*N+1)/6;
        ll S=0,S2=0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                S+=grid[i][j];
                S2+=(ll)(grid[i][j]*grid[i][j]);
            }
        }

        ll val1 = S-SN;
        ll val2diff = S2-S2N;
        if(val1==0) return {-1,-1};
        ll val2 = (val2diff/val1);
        ll x = (val1+val2)/2;
        ll y = x-val1;
        return {(int)x, (int)y};
    }
};