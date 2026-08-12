class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int buyP = INT_MAX;
        for(int i=0; i<prices.size(); i++) {
            //currPrice > prevBuy price
            if(prices[i]>buyP) { //sell stocks
                int prof = prices[i]-buyP;
                maxProf = max(maxProf, prof);
            } else { //buy stocks
                buyP = prices[i];
            }
        }

        return maxProf;
    }
};