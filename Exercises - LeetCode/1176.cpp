class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower, int upper) {

        int startWindow = 0;
        int size = calories.size();
        int currentCalories = 0;
        for (int endWindow = 0; endWindow < size; endWindow++) {
            currentCalories += calories[endWindow];

            if (endWindow - startWindow + 1 > k) {

            }
        }
    }
};
