class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // creo un vector para guardar de a k grupos de numeros
        int size = nums.size();
        int n = size - k + 1;
        vector<int> dp(n, 0);

        int sum = 0;
        // como un sliding window
        for (int i = 0; i < size; i++) {
            sum += nums[i];

            // si i es mayor que k, significa que tengo más elementos de los que necesito para el grupo
            if (i >= k) {
                sum -= nums[i - k];
            }

            // si tengo la cantidad que necesito para el grupo (k), guardo el valor
            if (i >= k - 1) {
                dp[i - k  + 1] = sum;
            }
        }

        vector<int> left(n, 0);
        int maxIndex = 0;
        // de izq a derecha
        for (int i = 0; i < n; i++) {
            if (dp[i] > dp[maxIndex]) {
                maxIndex = i;
            }
            left[i] = maxIndex;
        }

        vector<int> right(n, 0);
        maxIndex = n - 1;
        // de derecha a izq
        for (int i = n - 1; i >= 0; i--) {
            if (dp[i] >= dp[maxIndex]) {
                maxIndex = i;
            }
            right[i] = maxIndex;
        }


        vector<int> res(3,-1);
        // pivoteo el elemento del medio buscando el mayor para maximizar
        for (int i = k; i < n - k; i++) {
            if (res[0] == -1 || dp[res[0]] + dp[res[1]] + dp[res[2]] < dp[left[i - k]] + dp[i] + dp[right[i + k]]) {
                res[0] = left[i - k];
                res[1] = i;
                res[2] = right[i + k];
            }
        }
        return res;
    }
};
