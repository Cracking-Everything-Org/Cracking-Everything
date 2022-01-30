class Solution {
public:
    int numFriendRequests(vector<int>& ages) {

        /*
            Instead of processing all 20000 people, we can process pairs of (age, count)
            representing how many people are that age. Since there are only 120 possible
            ages, this is a much faster loop.
        */

        vector<int> count(121,0);
        for (int age: ages) {
            count[age]++;
        }

        int ans = 0;
        for (int ageA = 0; ageA <= 120; ageA++) {
            int countA = count[ageA];
            for (int ageB = 0; ageB <= 120; ageB++) {
                int countB = count[ageB];
                if (ageB <= ageA * 0.5 + 7 ) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;
                ans += countA * countB;
                /*
                    If ageA == ageB, then we overcounted:
                    we should have countA * (countA - 1) pairs of
                    people making friend requests instead, as you cannot friend request yourself.
                */
                if (ageA == ageB) {
                    ans -= countA;
                }
            }
        }
        return ans;
    }
    /*
    Time Complexity:
    O(A^2+N),
    where N is the number of people, and A is the number of ages.

    Space Complexity:
    O(A),
    the space used to store count.
    */
};
