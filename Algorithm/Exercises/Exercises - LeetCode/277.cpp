/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // defino el primer potencial celebrity
        int celebrity = 0;
        for (int i = 1; i < n; i++) {
            if (knows(celebrity, i)) {
                celebrity = i;
            }
        }

        // recorro otra vez para saber si alguien no conoce a la celebridad
        // o si la celebridad no conoce a alguien
        for (int i = 0; i < n; i++) {
            if (celebrity != i && (knows(celebrity, i) || !knows(i, celebrity))) {
                return -1;
            }
        }
        return celebrity;
    }
};
