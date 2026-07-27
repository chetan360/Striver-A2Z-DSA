class Solution {
public:
    // class Node {
    // public:
    //     Node* children[26];
    //     bool eow;
    //     int childCnt;

    //     Node() {
    //         eow = false;
    //         childCnt = 0;
    //         for(int i=0; i<26; i++)
    //             children[i] = nullptr;
    //     }
    // };

    // void insert(Node* root, string word) {
    //     Node* curr = root;
    //     for(char ch: word) {
    //         int idx = ch - 'a';
    //         if(!curr->children[idx]) {
    //             curr->children[idx] = new Node();
    //             curr->childCnt++;
    //         }
    //         curr = curr->children[idx];
    //     }
    //     curr->eow = true;
    // }

    string longestCommonPrefix(vector<string>& strs) {
        // if(strs.empty()) return "";

        // Node* root = new Node();
        // for(string word: strs)
        //     insert(root, word);
        
        // string commPrefix = "";
        // Node* curr = root;
        // string searchWord = strs[0];
        // for(char ch: searchWord) {
        //     if(curr->childCnt != 1 || curr->eow)
        //         break;
        //     int idx = ch -'a';
        //     commPrefix += ch;
        //     curr = curr->children[idx];
        // }

        string commPrefix = "";
        sort(strs.begin(), strs.end());
        int n=strs.size();
        string first = strs[0], last = strs[n-1];
        for(int i=0; i<min(first.length(), last.length()); i++) {
            if(first[i]!=last[i])
                return commPrefix;
            commPrefix += first[i];
        }
        
        return commPrefix;
    }
};