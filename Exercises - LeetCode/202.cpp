class Solution {
public:

    bool isHappy(int n) {
        int slower = n;
        int faster = getNext(getNext(n));
        while (faster != 1 && slower != faster) {
            slower = getNext(slower);
            faster = getNext(getNext(faster));
        }
        return faster == 1;
    }

    int getNext(int n) {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }

};
