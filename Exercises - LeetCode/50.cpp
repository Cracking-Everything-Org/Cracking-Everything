class Solution {
public:

    /*  FAST EXPONENTIATION (Modular exponentiation)

        x^n = (x^2)^(n/2) if n is even (par)    2^4 = (2^2)^(4/2) = 4^2 = 16
        // mirando al caso del par, puedo deducir el de impar
        n^5 = x(x^(n-1)) -> x(x^2)^((n-1)/2) if n is odd (impar)
    */

    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0) {
            return myPow(1/x, -n);
        }
        if (n % 2 == 0) {
            return myPow(x*x, n/2);
        } else {
            return x * myPow(x*x, (n-1)/2);
        }
    }
};
