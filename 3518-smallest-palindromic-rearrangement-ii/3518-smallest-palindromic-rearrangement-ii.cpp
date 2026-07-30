class Solution {
private:
    long long nCr(int n, int r) {
        if (r > n || r < 0) return 0; //nC-ve = nCr>n = 0
        if (r == 0 || r == n) return 1; //nC0 = nCn = 1
        if (r > n - r) r = n - r; //nCr = nCn-r
        
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
        const long long CAP = 1e15; //to prevent overflow
        long long acc = 1;
        for(int ci=0; ci<26; ci++) {
            int f = freq[ci];
            if(!f) continue;
            if(f>rem) return 0; //char with +ve freq
            
            long long ncr = nCr(rem, f); //calculate no. of combinations
            
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
        int half = n/2; //left part
        int freq[26] = {0}; 
        // count freq of each char from left part
        for(int i=0; i<half; i++)
            freq[s[i]-'a']++;

        string left = "";
        long long start = 0; //no. of prmutations to skip
        for(int i=0; i<half; i++) {
            bool selected = false; 
            for(int ci=0; ci<26; ci++) {
                if(!freq[ci]) continue;
                freq[ci] -= 1;
                
                long long p = perm(freq, half-i-1, k); //calculate permutation
                if(start+p>=k) { //found best candidate
                    left += ci+'a';
                    selected = true;
                    break;
                }

                //not get best candidate
                //add back freq of char
                freq[ci] += 1;
                start += p; //store skiped permutation
            }
            if(!selected) return "";
        }

        string h1=left; //left part
        string mid = (n % 2 == 1) ? string(1, s[n/2]) : ""; //middle char if odd
        string h2 = left; //right part (reverse of left)
        reverse(h2.begin(), h2.end());
        return h1+mid+h2; //kth smallest pandromic string
    }
};