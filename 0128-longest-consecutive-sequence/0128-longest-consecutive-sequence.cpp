class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int longest=1;
        for(int it: s) {
            int cnt=1;
            int x=it;
            if(s.find(x-1)==s.end()) {//not in set
                cnt=1;
                x=it;//new elt
                while(s.find(x+1)!=s.end()) {//x+1 in set
                    x+=1;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
            
        }

        return longest;
    }
};