class Solution {
public:
    long long func(vector<int>& piles, int h) {
        int n = piles.size();
        long long totalH=0;
        for(int i=0; i<n; i++) {
            totalH += ceil((double)piles[i]/(double)h);
        }

        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1, high = *max_element(piles.begin(), piles.end());
        
        while(low<=high) {
            int mid = low+(high-low)/2;
            long long totalH = func(piles, mid);

            if(totalH<=h) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low;
    }
};