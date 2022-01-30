class Solution {
public:
    double myPow(double x, int n) {
        return powUtil(x, n);
    }
    
    // x^n = (x^2)^(n/2)   -- Exponentiation by squaring   https://wikimedia.org/api/rest_v1/media/math/render/svg/46fe9e68c70c04df4c3d22c469a57d4655b50539
    // even case -> (x^2)^(n/2)
    // odd case -> x * (x^2)^(n/2)
    
    double powUtil(double x, long n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n < 0) {
            return powUtil(1/x, -n);
        }
        double result = powUtil(x*x, n/2);
        if (n % 2) result *= x;
        return result;
    }
    // log n
};