class Solution {
public:
    string reverseWords(string s) {
        //  int n = s.size();
        // string res = "";
        // reverse(s.begin(), s.end());
        // for(int i=0; i<n; i++) {
        //     string word="";
        //     while(i<n && s[i]!=' ') {
        //         word += s[i];
        //         i++;
        //     }
        //     reverse(word.begin(), word.end());
        //     if(word.size() > 0)
        //         res += " " +word;
        // }

        // return res.substr(1);

        // two pointer approch
        int n = s.size();
        string res = "";
        int i=s.size()-1;
        while(i >= 0) {
            //remove word ke end wale space
            while(i>=0 && s[i] == ' ')
                i--;
            // invalid idx i
            if(i<0) break;
            
            // start idx dhundo
            int j=i;
            // agar char he to j-- & ' ' hoto ruk jao 
            while(j>=0 && s[j] != ' ')
                j--;
            // word ko add kardo
            res += s.substr(j+1, i-j);
            
            // remove word ke age wale space
            while(j>=0 && s[j] == ' ')
                j--;
            // agar j>=0 he to last word nahi he
            // to ek ' ' laga do
            if(j>=0) res += " ";
            i=j;
        }

        return res;
    }
};