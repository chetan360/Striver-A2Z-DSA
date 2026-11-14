class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int cnt=0, bouquets=0;
        int n = bloomDay.size();
        for(int i=0; i<n; i++) {
            if(bloomDay[i]<=day) cnt++;
            else {
                bouquets += cnt/k;
                cnt = 0;
            }
        }
        bouquets += cnt/k;
        if(bouquets>=m) return true;
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n<1LL*m*k) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(possible(bloomDay, mid, m, k)) {
                //ans mil gaya to mini chahiye eliminate right half
                r = mid-1;
            } else l = mid+1;
        }
        return l;
    }
};
