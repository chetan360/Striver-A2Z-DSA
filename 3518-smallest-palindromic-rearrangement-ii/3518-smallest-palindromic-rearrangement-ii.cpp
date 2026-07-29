class Solution {
private:
    long long nCr(int n, int r) {
        if (r > n || r < 0) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        
        const long long CAP = 1e15;
        long long result = 1;
        for (int i = 0; i < r; i++) {
            long long multiplier = n - i;
            
            // Check BEFORE multiplication to prevent overflow
            if (result > CAP / multiplier) {
                return CAP;
            }
            
            result = result * multiplier / (i + 1);
        }
        return result;
    }

public:
    long long perm(int freq[], int rem, int k){
        const long long CAP = 1e15;
        long long acc = 1;
        for(int ci=0; ci<26; ci++) {
            int f = freq[ci];
            if(!f) continue;
            if(f>rem) return 0;
            
            long long ncr = nCr(rem, f);
            
            // Check BEFORE multiplication to prevent overflow
            if (ncr > 0 && acc > CAP / ncr) {
                return CAP;
            }
            
            acc *= ncr;
            if(acc > k) return acc;
            rem -= f;
        }
        return acc;
    }

    string smallestPalindrome(string s, int k) {
        int n = s.size();
        int half = n/2;
        int freq[26] = {0};
        for(int i=0; i<half; i++)
            freq[s[i]-'a']++;

        string left = "";
        long long start = 0;
        for(int i=0; i<half; i++) {
            bool selected = false;
            for(int ci=0; ci<26; ci++) {
                if(!freq[ci]) continue;
                freq[ci] -= 1;
                
                long long p = perm(freq, half-i-1, k);
                if(start+p>=k) {
                    left += ci+'a';
                    selected = true;
                    break;
                }

                freq[ci] += 1;
                start += p;
            }
            if(!selected) return "";
        }

        string h1=left;
        string mid = (n % 2 == 1) ? string(1, s[n/2]) : "";
        string h2 = left;
        reverse(h2.begin(), h2.end());
        return h1+mid+h2;
    }
};