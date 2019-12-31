class Solution {
public:
    int fib(int N) {
        unordered_map<int, int> fib;
        if(N<=1) return N;
        fib[0] = 0;
        fib[1] = 1;
        for(int i=2; i<=N; i++)
            fib[i] = fib[i-1] + fib[i-2];
        return fib[N];
    }
};
