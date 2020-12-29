class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int rotations = check(A[0], B, A, n);
        if (rotations != -1 || A[0] == B[0]) return rotations;
        else return check(B[0], B, A, n);
      }

    int check(int x, vector<int>& A, vector<int>& B, int n) {
    // how many rotations should be done
    // to have all elements in A equal to x
    // and to have all elements in B equal to x
    int rotations_a = 0;
    int rotations_b = 0;
    for (int i = 0; i < n; i++) {
      // rotations coudn't be done
      if (A[i] != x && B[i] != x) return -1;
      // A[i] != x and B[i] == x
      else if (A[i] != x) rotations_a++;
      // A[i] == x and B[i] != x
      else if (B[i] != x) rotations_b++;
    }
    // min number of rotations to have all
    // elements equal to x in A or B
    return min(rotations_a, rotations_b);
  }
};
