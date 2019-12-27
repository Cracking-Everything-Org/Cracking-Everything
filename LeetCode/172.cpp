class Solution {
public:
    int factorialF(int n) {
      return (n == 1 || n == 0) ? 1 : factorialF(n - 1) * n;
    }

    int trailingZeroes(int n) {
        int factorial = factorialF(n);
        string str = to_string(factorial);
        int zeros = 0;
        for(char c : str){
            if(c=='0')zeros++;
        }
        return zeros;
    }
};
