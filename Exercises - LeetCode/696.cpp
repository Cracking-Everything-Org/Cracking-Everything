class Solution {
public:
    int countBinarySubstrings(string s) {
        int ways=0;
        int conZeros = 0;
        int conOnes = 0;
        int offset = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='0'){
                while(s[i]=='0'){
                    conZeros++;
                    i++;
                }
                while(s[i]=='1'){
                    conOnes++;
                    i++;
                }
                offset = conOnes+1;
            } else {
                while(s[i]=='1'){
                    conOnes++;
                    i++;
                }
                while(s[i]=='0'){
                    conZeros++;
                    i++;
                }
                offset = conZeros+1;
            }
            if(conZeros == 0 || conOnes == 0) break;
            int mini = min(conOnes,conZeros);
            ways += (mini+mini)/2;
            i-=offset;
            conZeros = 0;
            conOnes = 0;
        }
        return ways;
    }
};
