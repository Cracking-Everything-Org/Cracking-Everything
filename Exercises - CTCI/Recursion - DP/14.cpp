using namespace std;
#include <string>    
#include <unordered_map>    

int countEval(string s, bool result, unordered_map<string, int> memo) {
    if(s.length()==0) return 0;
    if(s.length()==1) return stringToBool(s) == result ? 1 :0;
    if(memo[result+s]) return memo[result+s];

    int ways=0;
    for(int i=1; o<s.length(); i+=2){
        char c = s[i];
        string left = s.substr(0, i-1);
        string right = s.substr(i+1, s.length()-1);
        int leftTrue = countEval(left, true, memo);
        int leftFalse = countEval(left, false, memo);
        int rightTrue = countEval(right, true, memo);
        int rightFalse = countEval(right, false, memo);
        int total=(leftTrue + leftFalse) * (rightTrue + rightFalse);

        int totalTrue =0;
        if(c=='^') totalTrue = leftTrue*rightFalse + leftFalse*rightTrue;
        if(c=='&') totalTrue = leftTrue*rightTrue;
        else if(c=='|') totalTrue = leftFalse*rightTrue + leftTrue*rightFalse + leftTrue*rightTrue;

        int subWays = result ? totalTrue : total - totalTrue;
        ways+=subWays;
    }
    memo[result+s]=ways;
    return ways;
}