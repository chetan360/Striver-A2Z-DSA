class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // douplicate words filter kardo
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        // chars ko as nodes mano and BFS perform karo 
        
        queue<int> q;
        vector<bool> seen(s.length(), false);
        q.push(0);

        while(!q.empty()) {
            int st = q.front();
            q.pop();

            // start end tak chala gaya yani sub words he set me
            // and string ke bhi end tak aa gaye last node of bfs
            if(st == s.length())
                return true;
            
            for(int ed=st+1; ed<=s.length(); ed++) {
                if(seen[ed])
                    continue;
                
                // agar startIdx se leke endIdx tak ka word
                // set me he to queue endIdx dal ke seen true kardo
                if(words.find(s.substr(st, ed-st)) != words.end()) {
                    q.push(ed);
                    seen[ed] = true;
                }
            }
        }

        return false;
    }
};