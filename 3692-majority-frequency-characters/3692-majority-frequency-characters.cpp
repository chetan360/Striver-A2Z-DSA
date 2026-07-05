class Solution {
public:
    string majorityFrequencyGroup(string s) {
        //countiung freq.
        vector <int> freq(26,0);
        for(char ch: s) 
            freq[ch-'a']++;

        //maping freq. -> group size
        unordered_map<int, int> group_sizes;
        for(int i=0; i<26; i++) 
            if(freq[i]>0) group_sizes[freq[i]]++;

        //finding max freq. and group
        int max_freq=0, max_group=0;
        for(auto& [f, cnt]: group_sizes) {
            if(cnt>max_group) {
                max_freq = f;
                max_group = cnt;
            } else if(cnt == max_group && f>max_freq) max_freq = f;
        }

        //collecting max freq. char group
        string majority;
        for(int i=0; i<26; i++) 
            if(freq[i] == max_freq) majority.push_back('a'+i);

        return majority;
    }
};