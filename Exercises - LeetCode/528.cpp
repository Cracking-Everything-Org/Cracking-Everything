class Solution {
public:
    vector<int> nums;

    Solution(vector<int>& w) {
        this->nums = w;
    }

    // Guardo el acumulado de los pesos de izq a derecha en un vector
    // selecciono un random entre el 1 y el maximo acumulado
    // hago un binary search en el vector de acumulado, me quedo con el indice que sea <= al random
    // [1,4,8,12], rand = 5, retorno el indice del 4, que es 1.

    int pickIndex() {

        vector<int> accumulatedWeights(nums.size(), 0);
        accumulatedWeights[0] = nums[0];
        for (int i=1; i < nums.size(); i++) {  // O(n)
            accumulatedWeights[i] = accumulatedWeights[i-1] + nums[i];
        }

        int random = rand() % accumulatedWeights[nums.size() - 1] + 1; // not inclusive

        return accumulatedIndex(random, accumulatedWeights);
    }

    int accumulatedIndex(int random, vector<int> accumulatedWeights) {
        int left = 0;
        int right = accumulatedWeights.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (accumulatedWeights[mid] <= random) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
