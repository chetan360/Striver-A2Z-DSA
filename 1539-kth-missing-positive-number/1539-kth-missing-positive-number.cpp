class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for(int x:arr)
            freq[x]++;
        int mx = *max_element(arr.begin(), arr.end());
        int counter=0;
        int kth = -1;
        for(int i=1; i<=mx+k; i++) {
            if(freq[i]==0) {
                counter++;
                if(counter==k)
                    kth = i;
            }
        }

        return kth;
    }
};