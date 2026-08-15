class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int elt1, elt2;
        elt1=elt2=INT_MIN;
        int cnt1=0, cnt2=0;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(cnt1==0 && nums[i]!=elt2) {
                elt1=nums[i];
                cnt1=1;
            } else if(cnt2==0 && nums[i]!=elt1) {
                elt2=nums[i];
                cnt2=1;
            } else if(nums[i]==elt1) {
                cnt1++;
            } else if(nums[i]==elt2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1=cnt2=0;
        for(int i=0; i<n; i++) {
            if(nums[i]==elt1) cnt1++;
            else if(nums[i]==elt2) cnt2++;
        }

        int mini = (int)(n/3)+1;
        if(cnt1>=mini) ans.push_back(elt1);
        if(cnt2>=mini) ans.push_back(elt2);

        return ans;
    }
};