struct Comparator {
    bool operator()(pair<int,string> a, pair<int, string> b) {
        if(a.first == b.first) 
            return a.second > b.second;
        
        return a.first < b.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        int n = words.size();
        for(int i=0; i<n; i++)
            mp[words[i]]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Comparator> pq;
        for(auto it:mp)
            pq.push({it.second, it.first});

        vector<string> res;
        while(k--) {
            pair<int, string> a = pq.top();
            pq.pop();
            res.push_back(a.second);
        }

        return res;
    }
};