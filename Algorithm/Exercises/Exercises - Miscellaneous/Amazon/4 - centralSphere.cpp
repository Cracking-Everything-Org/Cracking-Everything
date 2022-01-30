// you can use includes, for example:
 #include <algorithm>
 #include <math.h> 
 #include <unordered_set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<Point3D> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> radiusNeeded;
    
    for (int point = 0; point < A.size(); point++) {
        int radiusSquare = (pow(A[point].x, 2) + pow(A[point].y, 2) + pow(A[point].z, 2));
        if (radiusNeeded.find(radiusSquare) == radiusNeeded.end()) {
            radiusNeeded.insert(radiusSquare);
        }
    }
    
    return radiusNeeded.size();
}
