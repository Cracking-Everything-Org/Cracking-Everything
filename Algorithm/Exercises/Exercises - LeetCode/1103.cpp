class Solution {
public:
      vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people);
        int counter = 0;
        while (candies) {
            ans[counter % num_people] += candies > counter + 1 ? counter + 1: candies;
            if (candies > counter + 1) {
                candies -= counter+1;
            } else {
                candies = 0;
            }
            counter++;
        }
        return ans;
    }
};
