class Solution {
public:

    unordered_map<int, int>hs;
    int tribonacci(int n) {
        if(n<2) return n;
        if(n==2) return 1;
        if(n==2) return 1;
        if(hs.find(n-1)==hs.end()) hs[n-1]=tribonacci(n-1);
        if(hs.find(n-2)==hs.end()) hs[n-2]=tribonacci(n-2);
        if(hs.find(n-3)==hs.end()) hs[n-3]=tribonacci(n-3);
        return hs[n-1]+hs[n-2]+hs[n-3];   
    }
};
