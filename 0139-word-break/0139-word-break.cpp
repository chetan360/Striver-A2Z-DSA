class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // removing douplicate words
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        // treat string chars as nodes and perform BFS 
        // queue to track start node
        queue<int> q;
        // seen vector for visited nodes
        vector<bool> seen(s.length(), false);
        // firts node
        q.push(0);

        // if not empty
        while(!q.empty()) {
            // start nikalo
            int st = q.front();
            q.pop();

            // start end tak chala gaya yani sub words he set me
            if(st == s.length())
                return true;
            
            for(int ed=st+1; ed<=s.length(); ed++) {
                if(seen[ed])
                    continue;
                
                if(words.find(s.substr(st, ed-st)) != words.end()) {
                    q.push(ed);
                    seen[ed] = true;
                }
            }
        }

        return false;
    }
};