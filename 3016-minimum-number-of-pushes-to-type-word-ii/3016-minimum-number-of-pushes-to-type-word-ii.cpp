class Solution {
public:
    int minimumPushes(string word) {
        unordered_map <char, int> freqMp;
        for(char& ch: word)
            freqMp[ch]++;
        
        priority_queue<int> freqQ;
        for(const auto& entry: freqMp)
            freqQ.push(entry.second);
        
        int totalPushes = 0;
        int idx = 0;
        while(!freqQ.empty()) {
            totalPushes += (1+(idx/8))*freqQ.top();
            freqQ.pop();
            idx++;
        }

        return totalPushes;
    }
};