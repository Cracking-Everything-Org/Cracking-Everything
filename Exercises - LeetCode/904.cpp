class Solution {
public:
    int totalFruit(vector<int>& tree) {

        unordered_map<int,int> frequencyMap;
        int maxFruits = 0;
        int startPointer = 0;

        for (int endPointer = 0; endPointer < tree.size(); endPointer++) {

            frequencyMap[tree[endPointer]]++;

            if (frequencyMap.size() <= 2) {
                maxFruits = max(maxFruits, endPointer - startPointer + 1);
            }

            while (frequencyMap.size() > 2) {
                frequencyMap[tree[startPointer]]--;
                if(frequencyMap[tree[startPointer]] == 0) {
                    frequencyMap.erase(tree[startPointer]);
                }
                startPointer++;
            }

        }
        return maxFruits;
    }
};
