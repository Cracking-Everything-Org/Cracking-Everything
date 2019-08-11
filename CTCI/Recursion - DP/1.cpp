using namespace std;
#include <vector>

int tripleStep(int n){
    vector<int> memo;
    for(int i=0; i<=n; i++){
        memo[i] = -1;
    }
    return tripleStep(n, memo);
}

int tripleStep(int n, vector<int> memo){
    if(n<0) return 0;
    if(n==0) return 1;
    else if (memo[n]!=-1) return memo[n];
    else{
        memo[n] = tripleStep(n-3) + tripleStep(n-2) + tripleStep(n-1);
        return memo[n];
    }
}