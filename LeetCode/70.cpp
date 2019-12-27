class Solution {
public:
    unordered_map<int,int> memo;
    int climbStairs(int i) {
        if (memo.find(i)!=memo.end()){
            return memo[i];
        }
        if (i<2){
            return memo[i]=1;
        }
        return memo[i] = climbStairs(i-2) + climbStairs(i-1);
    }

};
