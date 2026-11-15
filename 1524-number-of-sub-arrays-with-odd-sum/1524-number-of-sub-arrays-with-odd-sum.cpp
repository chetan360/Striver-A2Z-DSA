class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9+7;
        int n = arr.size();
        int preSum = 0;
        int evenCnt = 1, oddCnt = 0, cnt = 0;
        
        for(int x:arr) {
            preSum += x;
            
            if(preSum%2==0) {
                cnt += oddCnt;
                evenCnt++;
            } else {
                cnt += evenCnt;
                oddCnt++;
            }
            cnt %= MOD;
        }         
                
        return cnt%MOD;
    }
};