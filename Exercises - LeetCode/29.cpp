class Solution {
public:
    int divide(int dividend, int divisor) {
        // BIT MANIPULATION
        
        //OVERFLOW CASE
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        long a = labs(dividend); // labs es el abs de long
        long b = labs(divisor);
        int res = 0;
        while (a - b >= 0) {
            int x = 0;
            while(a - (b << x << 1) >= 0){
                x++;
            }
            res += 1 << x;
            a -= b << x;
        }
        return (dividend >= 0) == (divisor >= 0) ? res : -res;
    }
};
